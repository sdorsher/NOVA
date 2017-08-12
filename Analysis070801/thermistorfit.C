#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

#define NUMLINES1 60
#define NUMLINES2 60
#define NUMPTS 231
#define LOWTEMP -80
#define NUMFULLLINES2 51
#define R25C 10.
#define MINPT 40
#define MAXPT 120

int thermistorfit(){
  
  ifstream infile1;
  ifstream infile2;
  char entry[20];
  int temperatureC;
  float temperatureK[NUMPTS];
  float resistance[NUMPTS];
  int linenum;

  infile1.open("../Data/page1thermisterdata.txt");
  infile2.open("../Data/page2thermisterdata.txt");
  
  for(linenum=0;linenum<NUMLINES1;linenum++){
    infile1.getline(entry,20,' ');
    stringstream(entry) >> temperatureC;
    temperatureK[temperatureC-LOWTEMP]=1.0*temperatureC+273.15;
    //cout <<temperatureC << "\n";
    infile1.getline(entry,20,' ');
    infile1.getline(entry,20,' ');
    infile1.getline(entry,20,' ');
    infile1.getline(entry,20,' ');
    stringstream(entry) >> resistance[temperatureC-LOWTEMP];;
    infile1.getline(entry,20,' ');
    
    infile1.getline(entry,20,' ');
    stringstream(entry) >> temperatureC;
    temperatureK[temperatureC-LOWTEMP]=1.0*temperatureC+273.15;
    infile1.getline(entry,20,' ');
    infile1.getline(entry,20,' ');
    infile1.getline(entry,20,' ');
    infile1.getline(entry,20,' ');
    stringstream(entry) >> resistance[temperatureC-LOWTEMP];;
    infile1.getline(entry,20,'\n');
  }

  for(linenum=0;linenum<NUMFULLLINES2;linenum++){
    infile2.getline(entry,20,' ');
    stringstream(entry) >> temperatureC;
    temperatureK[temperatureC-LOWTEMP]=1.0*temperatureC+273.15;
    infile2.getline(entry,20,' ');
    infile2.getline(entry,20,' ');
    infile2.getline(entry,20,' ');
    infile2.getline(entry,20,' ');
    stringstream(entry) >> resistance[temperatureC-LOWTEMP];;
    //cout << resistance[temperatureC-LOWTEMP] <<"\n";
    infile2.getline(entry,20,' ');
    
    infile2.getline(entry,20,' ');
    stringstream(entry) >> temperatureC;
    temperatureK[temperatureC-LOWTEMP]=1.0*temperatureC+273.15;
    infile2.getline(entry,20,' ');
    infile2.getline(entry,20,' ');
    infile2.getline(entry,20,' ');
    infile2.getline(entry,20,' ');
    stringstream(entry) >> resistance[temperatureC-LOWTEMP];;
    infile2.getline(entry,20,'\n');
  }

 for(linenum=NUMFULLLINES2;linenum<NUMLINES2;linenum++){
   infile2.getline(entry,20,' ');
   stringstream(entry) >> temperatureC;
   temperatureK[temperatureC-LOWTEMP]=1.0*temperatureC+273.15;
   infile2.getline(entry,20,' ');
   infile2.getline(entry,20,' ');
   infile2.getline(entry,20,' ');
   infile2.getline(entry,20,' ');
   stringstream(entry) >> resistance[temperatureC-LOWTEMP];;
   //cout << temperatureC <<"\t" <<resistance[temperatureC-LOWTEMP]<<"\n";
   infile2.getline(entry,20,'\n');
 }
  

 int ptnum;
 float invT[MAXPT-MINPT+1];
 float lnR[MAXPT-MINPT+1];
 for(ptnum=0;ptnum<MAXPT-MINPT+1;ptnum++){
   invT[ptnum]=1./temperatureK[ptnum+MINPT];
   lnR[ptnum]=TMath::Log(resistance[ptnum+MINPT]/R25C);
   cout << ptnum << "\t" << temperatureK[ptnum] <<"\t" <<invT[ptnum] <<"\t" 
	<<resistance[ptnum] <<"\t" << lnR[ptnum]<< "\n";
 }
 
 

  
 TGraph *graph=new TGraph(MAXPT-MINPT+1,invT,lnR);
 graph->GetXaxis()->SetTitle("1/T (1/K)");
 graph->GetYaxis()->SetTitle("ln(R/R @ 25C)");
 gStyle->SetOptFit(1011);
 graph->Draw("ACP");
  
 graph->Fit("pol2");
}
