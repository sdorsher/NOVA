#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;


#define NUMOFFSETPTS 8 // number of points in toffsets.txt
#define NUMLINES4 40 // number of data lines in file to be calibrated

float findtemperature(float uncalT,float measured_temp[],float offset[]){
  float calT;
  int offsetptnum=0;

  //find spanning points
  while(measured_temp[offsetptnum]<uncalT){
    offsetptnum++;
  }
  if(offsetptnum>=NUMOFFSETPTS){
    offsetptnum=NUMOFFSETPTS-1;
  }
  if(offsetptnum<1){
    offsetptnum=1;
  }

  int top;
  int bottom;
  top=offsetptnum;
  bottom=offsetptnum-1;

  float weight;
  //interpolate
  weight=(uncalT-measured_temp[bottom])/
    (measured_temp[top]-measured_temp[bottom]);
  float interp_offset; //interpolated offset
  interp_offset=weight*(offset[top]-offset[bottom])+offset[bottom];
  
  calT=uncalT+interp_offset;
  
  //cout << uncalT <<"\t" << measured_temp[top] <<"\t" << measured_temp[bottom]
  //   << "\t" << offset[top] <<"\t" << offset[bottom] <<"\t" 
  //   <<interp_offset <<"\t"<<calT <<"\n";

  //calT=uncalT;
  return calT;
}

void calibrate(){
  ifstream offsetfile; //offset data file
  ifstream tempfile; //temperature data file
  ofstream outfile;
  int offsetptnum;
  int linenum;
  int apdnum;
  char entry[20];
  char header[200];

  offsetfile.open("toffsets.txt");
  tempfile.open("arrenhiusdata.txt");
  outfile.open("calibrated_arrheniusdata.txt");

  float temp_offset[NUMOFFSETPTS]; //temperature corresponding to offset data
  float offset_apd16[NUMOFFSETPTS];
  float offset_apd17[NUMOFFSETPTS];
  float offset_apd18[NUMOFFSETPTS];
  float offset_apd19[NUMOFFSETPTS];
  float measured_temp_apd16[NUMOFFSETPTS]; //what would be measured for each
  //apd corresponding to offset data.
  float measured_temp_apd17[NUMOFFSETPTS];
  float measured_temp_apd18[NUMOFFSETPTS];
  float measured_temp_apd19[NUMOFFSETPTS];


  offsetfile.getline(header,200,'\n');

  for(offsetptnum=0;offsetptnum<NUMOFFSETPTS;offsetptnum++){
    offsetfile.getline(entry,20,'\t');
    stringstream(entry)>> temp_offset[offsetptnum];
    offsetfile.getline(entry,20,'\t');
    stringstream(entry)>> offset_apd16[offsetptnum];
    measured_temp_apd16[offsetptnum]=
      temp_offset[offsetptnum]-offset_apd16[offsetptnum];
    offsetfile.getline(entry,20,'\t');
    stringstream(entry)>> offset_apd17[offsetptnum];
    measured_temp_apd17[offsetptnum]=
      temp_offset[offsetptnum]-offset_apd17[offsetptnum];
    offsetfile.getline(entry,20,'\t');
    stringstream(entry)>> offset_apd18[offsetptnum];
    measured_temp_apd18[offsetptnum]=
      temp_offset[offsetptnum]-offset_apd18[offsetptnum];
    offsetfile.getline(entry,20,'\n');
    stringstream(entry)>> offset_apd19[offsetptnum];
    measured_temp_apd19[offsetptnum]=
      temp_offset[offsetptnum]-offset_apd19[offsetptnum];
  }
 
  
  float uncalT;
  float calT;
  char restofline[200];
  tempfile.getline(header,200,'\n');
  outfile << header << "\n";
  for(linenum=0;linenum<NUMLINES4;linenum++){
    tempfile.getline(entry,20,'\t');
    stringstream(entry) >> apdnum;
    tempfile.getline(entry,20,'\t');
    stringstream(entry) >> uncalT;
    tempfile.getline(restofline,200,'\n');
    
    //find data points surrrounding uncalT in temp_offset+offset_apd#
    if(apdnum==16){
      calT=findtemperature(uncalT,measured_temp_apd16,offset_apd16);
    }else if(apdnum==17){
      calT=findtemperature(uncalT,measured_temp_apd17,offset_apd17);
    }else if(apdnum==18){
      calT=findtemperature(uncalT,measured_temp_apd18,offset_apd18);
    }else if(apdnum==19){
      calT=findtemperature(uncalT,measured_temp_apd19,offset_apd19);
    }
      

    cout << apdnum << "\t" <<uncalT <<"\t" << calT <<"\n";
    outfile << apdnum << "\t";
    outfile.width(12);
    outfile << calT <<"\t" << restofline <<"\n";
  }

  

  outfile.open("calibrated_arrheniusdata.txt");


  outfile.close();
  offsetfile.close();
  tempfile.close();

}
