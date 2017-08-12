

void thermistor() 
{
  std::vector<float> multiplier;
  std::vector<float> lnMultiplier;
  std::vector<float> temperature;

  for ( int i = -55; i <= 150; i+=5){
    temperature.push_back(1.0*i);
  }

  multiplier.push_back(54.92);
  multiplier.push_back(40.10);
  multiplier.push_back(29.60);
  multiplier.push_back(22.07);
  multiplier.push_back(16.61);
  multiplier.push_back(12.60);
  multiplier.push_back(9.638);
  multiplier.push_back(7.430);
  multiplier.push_back(5.778);
  multiplier.push_back(4.530);
  multiplier.push_back(3.580);
  multiplier.push_back(2.850);
  multiplier.push_back(2.281);
  multiplier.push_back(1.839);
  multiplier.push_back(1.493);
  multiplier.push_back(1.219);
  multiplier.push_back(1.000);
  multiplier.push_back(0.8265);
  multiplier.push_back(0.6857);
  multiplier.push_back(0.5730);
  multiplier.push_back(0.4805);
  multiplier.push_back(0.4048);
  multiplier.push_back(0.3427);
  multiplier.push_back(0.2915);
  multiplier.push_back(0.2491);
  multiplier.push_back(0.2138);
  multiplier.push_back(0.1843);
  multiplier.push_back(0.1594);
  multiplier.push_back(0.1384);
  multiplier.push_back(0.1205);
  multiplier.push_back(0.1053);
  multiplier.push_back(0.0924);
  multiplier.push_back(0.0813);
  multiplier.push_back(0.0719);
  multiplier.push_back(0.0637);
  multiplier.push_back(0.0566);
  multiplier.push_back(0.0504);
  multiplier.push_back(0.0450);
  multiplier.push_back(0.0403);
  multiplier.push_back(0.0362);
  multiplier.push_back(0.0326);
  multiplier.push_back(0.0294);

  cout << "multiplier size: " << multiplier.size() << endl;
  cout << "temperature size: " << temperature.size() << endl;

  for (int i = 0; i < multiplier.size(); i++)
    lnMultiplier.push_back( TMath::Log(multiplier[i]) );

  TGraph* gr = new TGraph(lnMultiplier.size(), &*(temperature.begin()), &*(lnMultiplier.begin()) );

  gr->GetXaxis()->SetTitle("degrees C");
  gr->GetYaxis()->SetTitle("ln multiplier on R @ 25C");
  gStyle->SetOptFit(1011);
  gr->Draw("ACP");

  gr->Fit("pol2");

}


