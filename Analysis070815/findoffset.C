#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

#define FITA 0.003353974
#define FITB 0.0002785557
#define FITC 4.923124e-6
#define NUMTLEVELS 9
#define NUMPTS2 1014
//#define NUMPTS2 3
#define NUMTHERMISTORS 20
#define R25C2 10000.

void findoffset(){
  ifstream infile;
  char header[20000];
  char entry[20];
  float rtd_101[NUMPTS2];
  float rtd_102[NUMPTS2];
  float true_temp[NUMPTS2];
  float R_thermistor[NUMTHERMISTORS][NUMPTS2];
  float T_thermistor[NUMTHERMISTORS][NUMPTS2];
  

  infile.open("../Data/thermistor_data.txt");
  int minpts[]={8,74,153,240,384,533,643,787,951};
  int maxpts[]={53,110,196,337,468,600,732,991,1008};
  
  infile.getline(header,20000,'\n');
  infile.getline(header,20000,'\n');

  int ptnum;
  int thnum;
  for(ptnum=0;ptnum<NUMPTS2;ptnum++){
    infile.getline(entry,20,'\t'); //discard entry number
    infile.getline(entry,20,'\t'); //discard time
    infile.getline(entry,20,'\t'); 
    stringstream(entry) >> rtd_101[ptnum];
    infile.getline(entry,20,'\t');
    stringstream(entry) >> rtd_102[ptnum];
    for(thnum=0;thnum<8;thnum++){
      infile.getline(entry,20,'\t');
      stringstream(entry) >> R_thermistor[thnum][ptnum];
      
    }
    R_thermistor[8][ptnum]=.001;
    for(thnum=9;thnum<NUMTHERMISTORS-1;thnum++){
      infile.getline(entry,20,'\t');
      stringstream(entry) >> R_thermistor[thnum][ptnum];
    }
    infile.getline(entry,20,'\n');
    stringstream(entry) >> R_thermistor[NUMTHERMISTORS-1][ptnum];
    //cout << ptnum <<"\t" <<rtd_101[ptnum] <<"\t" 
    // <<R_thermistor[0][ptnum] <<"\t"
    // <<R_thermistor[NUMTHERMISTORS-1][ptnum] <<"\n"
  }
  
  float logR;
  for(ptnum=0;ptnum<NUMPTS2;ptnum++){
    for(thnum=0;thnum<NUMTHERMISTORS;thnum++){
      logR=TMath::Log(R_thermistor[thnum][ptnum]/R25C2);
      T_thermistor[thnum][ptnum]=1./(FITA+FITB*logR+FITC*logR*logR)-273.15;
      //cout << thnum <<"\t" << ptnum <<"\t" 
      //<< FITA <<"\t" << FITB << "\t" << FITC <<"\t"
      //  << R_thermistor[thnum][ptnum] << "\t" << logR << "\t" <<
      //   T_thermistor[thnum][ptnum]<<"\n";

    }
    //cout << T_thermistor[1][ptnum] <<"\n";
  }

  
  int temp_level_num;
  float running_total;
  float true_T[NUMTLEVELS];
  float measured_T[NUMTHERMISTORS][NUMTLEVELS];
  int numptsinsum;
  float T_offset[NUMTHERMISTORS][NUMTLEVELS];
  for(temp_level_num=0;temp_level_num<NUMTLEVELS;temp_level_num++){
    for(thnum=0;thnum<NUMTHERMISTORS;thnum++){
      running_total=0.;
      numptsinsum=0;
      for(ptnum=minpts[temp_level_num];ptnum<=maxpts[temp_level_num];ptnum++){
	running_total=running_total+T_thermistor[thnum][ptnum];
	numptsinsum++;
      }
      measured_T[thnum][temp_level_num]=running_total/(1.0*numptsinsum);
      //cout << measured_T[thnum][temp_level_num] << "\n";
    }
    numptsinsum=0;
    running_total=0.;
    for(ptnum=minpts[temp_level_num];ptnum<=maxpts[temp_level_num];ptnum++){
      running_total=running_total+rtd_101[ptnum]+rtd_102[ptnum];
      numptsinsum++;
    }
    true_T[temp_level_num]=running_total/(2.*numptsinsum);
    for(thnum=0;thnum<NUMTHERMISTORS;thnum++){    
      T_offset[thnum][temp_level_num]=
	true_T[temp_level_num]-measured_T[thnum][temp_level_num];
    }
    cout << true_T[temp_level_num] << "\t" 
	 << measured_T[17][temp_level_num] <<"\t"
	 << T_offset[16][temp_level_num]<< "\t"
	 << T_offset[18][temp_level_num] << "\n";

  }

  ofstream outfile;
  outfile.open("toffsets.txt");
  outfile << "trueT \t \t APD16 \t\t APD17 \t\t APD18 \t\t APD19 \n";
  for(temp_level_num=1;temp_level_num<NUMTLEVELS;temp_level_num++){
    outfile.width(12);
    outfile <<true_T[temp_level_num] << "\t";
    outfile <<T_offset[15][temp_level_num] <<"\t"
	    <<T_offset[16][temp_level_num] <<"\t"
	    <<T_offset[17][temp_level_num] <<"\t"
	    <<T_offset[18][temp_level_num] <<"\n";
  }

  /* 
     float T_offset_th18[NUMTLEVELS];
     for(temp_level_num=0;temp_level_num<NUMTLEVELS;temp_level_num++){
     T_offset_th18[temp_level_num]=T_offset[17][temp_level_num];
     }
     
     TGraph *gr3=new TGraph(NUMTLEVELS,true_T,T_offset_th18);
     TCanvas *c2=new TCanvas();
     gr3->Draw("A*");
  */ 
  infile.close();
  outfile.close();
}
