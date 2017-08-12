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
  infile.open("calibrated_arrheniusdata.txt");

  std::getline(infile,header);

  for(linenum=0;linenum<NUMLINES;linenum++){
    infile.getline(entry,20,'\t');
    apdnum=strtol(entry,NULL,0);
    //cout <<apdnum << "\n";
    if(apdnum==16){
      infile.getline(entry,20,'\t');
      stringstream(entry) >> temp_apd16[linenum16];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> vM100_apd16[linenum16];
      //cout << vM100_apd16[linenum16] << "\n";
      infile.getline(entry,20,'\t');
      stringstream(entry) >> stddevM_apd16[linenum16];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> totalId_apd16[linenum16];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> avg_bulk_Id_apd16[linenum16];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> avg_slope_invMdMdV_apd16[linenum16];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> breakdownV_apd16[linenum16];
      infile.getline(entry,20,'\n');
      stringstream(entry) >> bad_run_apd16[linenum16]; 
      linenum16++;
    }else if(apdnum==17){
      infile.getline(entry,20,'\t');
      stringstream(entry) >> temp_apd17[linenum17];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> vM100_apd17[linenum17];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> stddevM_apd17[linenum17];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> totalId_apd17[linenum17];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> avg_bulk_Id_apd17[linenum17];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> avg_slope_invMdMdV_apd17[linenum17];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> breakdownV_apd17[linenum17];
      infile.getline(entry,20,'\n');
      stringstream(entry) >> bad_run_apd17[linenum17]; 
      //cout << bad_run_apd17[linenum17] << "\t" << linenum17<<"\n";
      linenum17++;
    }else if(apdnum==18){
      infile.getline(entry,20,'\t');
      stringstream(entry) >> temp_apd18[linenum18];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> vM100_apd18[linenum18];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> stddevM_apd18[linenum18];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> totalId_apd18[linenum18];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> avg_bulk_Id_apd18[linenum18];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> avg_slope_invMdMdV_apd18[linenum18];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> breakdownV_apd18[linenum18];
      infile.getline(entry,20,'\n');
      stringstream(entry) >> bad_run_apd18[linenum18]; 
      linenum18++;
    }else if(apdnum==19){
      infile.getline(entry,20,'\t');
      stringstream(entry) >> temp_apd19[linenum19];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> vM100_apd19[linenum19];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> stddevM_apd19[linenum19];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> totalId_apd19[linenum19];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> avg_bulk_Id_apd19[linenum19];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> avg_slope_invMdMdV_apd19[linenum19];
      infile.getline(entry,20,'\t');
      stringstream(entry) >> breakdownV_apd19[linenum19];
      infile.getline(entry,20,'\n');
      stringstream(entry) >> bad_run_apd19[linenum19]; 
      //cout << linenum19 <<"\t" << bad_run_apd19[linenum19] << "\n";
      linenum19++;
    }   
  }

  int tempptnum;
  float invT_apd16[NUMTPTS];
  float invT_apd17[NUMTPTS];
  float invT_apd18[NUMTPTS];
  float invT_apd19[NUMTPTS];

  for(tempptnum=0;tempptnum<NUMTPTS;tempptnum++){
    invT_apd16[tempptnum]=1.0/(temp_apd16[tempptnum]+273.15);
    invT_apd17[tempptnum]=1.0/(temp_apd17[tempptnum]+273.15);
    invT_apd18[tempptnum]=1.0/(temp_apd18[tempptnum]+273.15);
    invT_apd19[tempptnum]=1.0/(temp_apd19[tempptnum]+273.15);
    cout << invT_apd16[tempptnum] <<"\n";
  }

  //plot vM100
  TGraph *gr_vM100_apd16=new TGraph(NUMTPTS,invT_apd16,vM100_apd16);
  TCanvas *c1=new TCanvas("c1","Arrhenius Plots",200,10,600,400);
  c1->Divide(2,3);
  c1->cd(1);
  gr_vM100_apd16->SetMarkerStyle(21);
  gr_vM100_apd16->Draw("APL");
  gr_vM100_apd16->GetXaxis()->SetTitle("1/T (1/K)");
  gr_vM100_apd16->GetYaxis()->SetTitle("Voltage (V) at M=100");
  gr_vM100_apd16->GetXaxis()->CenterTitle();
  gr_vM100_apd16->GetYaxis()->CenterTitle();

  TGraph *gr_vM100_apd17=new TGraph(NUMTPTS,invT_apd17,vM100_apd17);
  gr_vM100_apd17->SetMarkerStyle(20);
  gr_vM100_apd17->Draw("PL");

  TGraph *gr_vM100_apd18=new TGraph(NUMTPTS,invT_apd18,vM100_apd18);
  gr_vM100_apd18->SetMarkerStyle(22);
  gr_vM100_apd18->Draw("PL");

  TGraph *gr_vM100_apd19=new TGraph(NUMTPTS,invT_apd19,vM100_apd19);
  gr_vM100_apd19->SetMarkerStyle(23);
  gr_vM100_apd19->Draw("PL");

  //plot stddevM

  TGraph *gr_stddevM_apd16=new TGraph(NUMTPTS,invT_apd16,stddevM_apd16);
  c1->cd(2);

  TGraph *gr_stddevM_apd19=new TGraph(NUMTPTS,invT_apd19,stddevM_apd19);
  gr_stddevM_apd19->SetMarkerStyle(23);
  gr_stddevM_apd19->Draw("APL");
  gr_stddevM_apd19->GetXaxis()->SetTitle("1/T (1/K)");
  gr_stddevM_apd19->GetYaxis()->SetTitle("Standard Deviation of M at M=100");
  gr_stddevM_apd19->GetXaxis()->CenterTitle();
  gr_stddevM_apd19->GetYaxis()->CenterTitle();

  gr_stddevM_apd16->SetMarkerStyle(21);
  gr_stddevM_apd16->Draw("PL");

  
  TGraph *gr_stddevM_apd18=new TGraph(NUMTPTS,invT_apd18,stddevM_apd18);
  gr_stddevM_apd18->SetMarkerStyle(22);
  gr_stddevM_apd18->Draw("PL");

  TGraph *gr_stddevM_apd17=new TGraph(NUMTPTS,invT_apd17,stddevM_apd17);
  gr_stddevM_apd17->SetMarkerStyle(20);
  gr_stddevM_apd17->Draw("PL");


  //plot totalId
  TGraph *gr_totalId_apd16=new TGraph(NUMTPTS,invT_apd16,totalId_apd16);
  c1->cd(3);
  gr_totalId_apd16->SetMarkerStyle(21);
  gr_totalId_apd16->Draw("APL");
  gr_totalId_apd16->GetXaxis()->SetTitle("1/T (1/K)");
  gr_totalId_apd16->GetYaxis()->SetTitle("Total Dark Current (A)at M=100");
  gr_totalId_apd16->GetXaxis()->CenterTitle();
  gr_totalId_apd16->GetYaxis()->CenterTitle();

  TGraph *gr_totalId_apd17=new TGraph(NUMTPTS,invT_apd17,totalId_apd17);
  gr_totalId_apd17->SetMarkerStyle(20);
  gr_totalId_apd17->Draw("PL");

  TGraph *gr_totalId_apd18=new TGraph(NUMTPTS,invT_apd18,totalId_apd18);
  gr_totalId_apd18->SetMarkerStyle(22);
  gr_totalId_apd18->Draw("PL");

  TGraph *gr_totalId_apd19=new TGraph(NUMTPTS,invT_apd19,totalId_apd19);
  gr_totalId_apd19->SetMarkerStyle(23);
  gr_totalId_apd19->Draw("PL");

  //plot avg_bulk_Id
  TGraph *gr_avg_bulk_Id_apd16=new TGraph(NUMTPTS,invT_apd16,avg_bulk_Id_apd16);
  c1->cd(4);
  gr_avg_bulk_Id_apd16->SetMarkerStyle(21);
  gr_avg_bulk_Id_apd16->Draw("APL");
  gr_avg_bulk_Id_apd16->GetXaxis()->SetTitle("1/T (1/K)");
  gr_avg_bulk_Id_apd16->GetYaxis()->SetTitle("Average Bulk Dark Current at M=100");
  gr_avg_bulk_Id_apd16->GetXaxis()->CenterTitle();
  gr_avg_bulk_Id_apd16->GetYaxis()->CenterTitle();

  TGraph *gr_avg_bulk_Id_apd17=new TGraph(NUMTPTS,invT_apd17,avg_bulk_Id_apd17);
  gr_avg_bulk_Id_apd17->SetMarkerStyle(20);
  gr_avg_bulk_Id_apd17->Draw("PL");

  TGraph *gr_avg_bulk_Id_apd18=new TGraph(NUMTPTS,invT_apd18,avg_bulk_Id_apd18);
  gr_avg_bulk_Id_apd18->SetMarkerStyle(22);
  gr_avg_bulk_Id_apd18->Draw("PL");

  TGraph *gr_avg_bulk_Id_apd19=new TGraph(NUMTPTS,invT_apd19,avg_bulk_Id_apd19);
  gr_avg_bulk_Id_apd19->SetMarkerStyle(23);
  gr_avg_bulk_Id_apd19->Draw("PL");


  //plot avg_slope_invMdMdV
  TGraph *gr_avg_slope_invMdMdV_apd16=new TGraph(NUMTPTS,invT_apd16,avg_slope_invMdMdV_apd16);
  c1->cd(5);
  gr_avg_slope_invMdMdV_apd16->SetMarkerStyle(21);
  gr_avg_slope_invMdMdV_apd16->Draw("APL");
  gr_avg_slope_invMdMdV_apd16->GetXaxis()->SetTitle("1/T (1/K)");
  gr_avg_slope_invMdMdV_apd16->GetYaxis()->SetTitle("Average slope of 1/M dM/dV");
  gr_avg_slope_invMdMdV_apd16->GetXaxis()->CenterTitle();
  gr_avg_slope_invMdMdV_apd16->GetYaxis()->CenterTitle();

  TGraph *gr_avg_slope_invMdMdV_apd17=new TGraph(NUMTPTS,invT_apd17,avg_slope_invMdMdV_apd17);
  gr_avg_slope_invMdMdV_apd17->SetMarkerStyle(20);
  gr_avg_slope_invMdMdV_apd17->Draw("PL");

  TGraph *gr_avg_slope_invMdMdV_apd18=new TGraph(NUMTPTS,invT_apd18,avg_slope_invMdMdV_apd18);
  gr_avg_slope_invMdMdV_apd18->SetMarkerStyle(22);
  gr_avg_slope_invMdMdV_apd18->Draw("PL");

  TGraph *gr_avg_slope_invMdMdV_apd19=new TGraph(NUMTPTS,invT_apd19,avg_slope_invMdMdV_apd19);
  gr_avg_slope_invMdMdV_apd19->SetMarkerStyle(23);
  gr_avg_slope_invMdMdV_apd19->Draw("PL");


  //plot breakdownV

  c1->cd(6);

  TGraph *gr_breakdownV_apd19=new TGraph(NUMTPTS,invT_apd19,breakdownV_apd19);
  gr_breakdownV_apd19->SetMarkerStyle(23);
  gr_breakdownV_apd19->Draw("APL");
  gr_breakdownV_apd19->GetXaxis()->SetTitle("1/T (1/K)");
  gr_breakdownV_apd19->GetYaxis()->SetTitle("Breakdown Voltage (V)");
  gr_breakdownV_apd19->GetXaxis()->CenterTitle();
  gr_breakdownV_apd19->GetYaxis()->CenterTitle();

  TGraph *gr_breakdownV_apd16=new TGraph(NUMTPTS,invT_apd16,breakdownV_apd16);
  
  gr_breakdownV_apd16->SetMarkerStyle(21);
  gr_breakdownV_apd16->Draw("PL");


  TGraph *gr_breakdownV_apd17=new TGraph(NUMTPTS,invT_apd17,breakdownV_apd17);
  gr_breakdownV_apd17->SetMarkerStyle(20);
  gr_breakdownV_apd17->Draw("PL");

  TGraph *gr_breakdownV_apd18=new TGraph(NUMTPTS,invT_apd18,breakdownV_apd18);
  gr_breakdownV_apd18->SetMarkerStyle(22);
  gr_breakdownV_apd18->Draw("PL");






}
