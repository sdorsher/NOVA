#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

#define NUMLINES 40
#define HEADERLENGTH 1
#define NUMTPTS 10

int run(){

  std::string header;
  char entry[20];
  long apdnum;
  float temp_apd16[NUMTPTS];
  float temp_apd17[NUMTPTS];
  float temp_apd18[NUMTPTS];
  float temp_apd19[NUMTPTS];
  float vM100_apd16[NUMTPTS];
  float vM100_apd17[NUMTPTS];
  float vM100_apd18[NUMTPTS];
  float vM100_apd19[NUMTPTS];
  float stddevM_apd16[NUMTPTS];
  float stddevM_apd17[NUMTPTS];
  float stddevM_apd18[NUMTPTS];
  float stddevM_apd19[NUMTPTS];
  float totalId_apd16[NUMTPTS];
  float totalId_apd17[NUMTPTS];
  float totalId_apd18[NUMTPTS];
  float totalId_apd19[NUMTPTS];
  float avg_bulk_Id_apd16[NUMTPTS];
  float avg_bulk_Id_apd17[NUMTPTS];
  float avg_bulk_Id_apd18[NUMTPTS];
  float avg_bulk_Id_apd19[NUMTPTS];
  float avg_slope_invMdMdV_apd16[NUMTPTS];
  float avg_slope_invMdMdV_apd17[NUMTPTS];
  float avg_slope_invMdMdV_apd18[NUMTPTS];
  float avg_slope_invMdMdV_apd19[NUMTPTS];
  float breakdownV_apd16[NUMTPTS];
  float breakdownV_apd17[NUMTPTS];
  float breakdownV_apd18[NUMTPTS];
  float breakdownV_apd19[NUMTPTS];
  long bad_run_apd16[NUMTPTS];
  long bad_run_apd17[NUMTPTS];
  long bad_run_apd18[NUMTPTS];
  long bad_run_apd19[NUMTPTS];
  int linenum;
  int linenum16=0;
  int linenum17=0;
  int linenum18=0;
  int linenum19=0;

  ifstream infile;
  infile.open("arrenhiusdata.txt");

  std::getline(infile,header);

  for(linenum=0;linenum<NUMLINES;linenum++){
    infile.getline(entry,20,'\t');
    apdnum=strtol(entry,NULL,0);
    cout <<apdnum << "\n";
    if(apdnum==16){
      infile.getline(entry,20,'\t');
      vM100_apd16[linenum16]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      stddevM_apd16[linenum16]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      totalId_apd16[linenum16]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      avg_bulk_Id_apd16[linenum16]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      avg_slope_invMdMdV_apd16[linenum16]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      breakdownV_apd16[linenum16]=strtof(entry,NULL);
      infile.getline(entry,20,'\n');
      bad_run_apd16[linenum16]=strtol(entry,NULL,0); 
      linenum16++;
    }else if(apdnum==17){
      infile.getline(entry,20,'\t');
      vM100_apd17[linenum17]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      stddevM_apd17[linenum17]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      totalId_apd17[linenum17]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      avg_bulk_Id_apd17[linenum17]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      avg_slope_invMdMdV_apd17[linenum17]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      breakdownV_apd17[linenum17]=strtof(entry,NULL);
      infile.getline(entry,20,'\n');
      bad_run_apd17[linenum17]=strtol(entry,NULL,0); 
      linenum17++;
    }else if(apdnum==18){
      infile.getline(entry,20,'\t');
      vM100_apd18[linenum18]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      stddevM_apd18[linenum18]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      totalId_apd18[linenum18]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      avg_bulk_Id_apd18[linenum18]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      avg_slope_invMdMdV_apd18[linenum18]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      breakdownV_apd18[linenum18]=strtof(entry,NULL);
      infile.getline(entry,20,'\n');
      bad_run_apd18[linenum18]=strtol(entry,NULL,0); 
      linenum18++;
    }else if(apdnum==19){
      infile.getline(entry,20,'\t');
      vM100_apd19[linenum19]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      stddevM_apd19[linenum19]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      totalId_apd19[linenum19]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      avg_bulk_Id_apd19[linenum19]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      avg_slope_invMdMdV_apd19[linenum19]=strtof(entry,NULL);
      infile.getline(entry,20,'\t');
      breakdownV_apd19[linenum19]=strtof(entry,NULL);
      infile.getline(entry,20,'\n');
      bad_run_apd19[linenum19]=strtol(entry,NULL,0); 
      linenum19++;
    }   
  }



}
