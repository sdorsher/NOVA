run(){
  Int_t n=20;
  Double_t x[20],y[20];
  for (Int_t i=0; i<n; i++){
    x[i]=i*.1;
    y[i]=10.*sin(x[i]+0.2);
  }
  TGraph *gr1 = new TGraph (n, x, y);
  TCanvas *c1=new TCanvas("c1","Graph Draw Options", 200,10,600,400);
  gr1->Draw("AC*");
}
