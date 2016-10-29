#include <iostream>
#include <cmath>
#include<iomanip>
#include <fstream>
using namespace std;
const int SIZE = 15;
int main()
  {
  double period[]{
    4.47e9 * 365 * 24 * 60 * 60,
    24.1 * 24 * 60 * 60,
    17 * 60,
    2.45e5 * 365 * 24 * 60 * 60,
    8e3 * 365 * 24 * 60 * 60 ,
    1.6 * 365 * 24 * 60 * 60,
    3.823 * 24 * 60 * 60,
    3.05 * 60,
    26.8 * 60,
    19.7 * 60,
    1.64e-4,
    22.3 * 365 * 24 * 60 * 60,
    5.01 * 24 * 60 * 60,
    138.4 * 24 * 60 * 60
    };
  double volume = 1.5e3;
  double density = 0.757;
  double consetration = 2e-8;
  double massOfCsintillyator = volume*density;
  double massOfUran = massOfCsintillyator*consetration;
  double molarMassofUran = 238.02891;
  double Na = 6.02e23;
  double N[SIZE]{};
  double dN[SIZE]{};
  N[0] = massOfUran*Na / molarMassofUran;
  cout << N[0];
  int time = 365 * 60 * 60 * 24;
  int t0 = 1;
  dN[0] = N[0] / period[0] * log(2)*t0;;
  ofstream f("result.txt");
  for (int t{}; t <= time; t=t+t0)
    {
    //cout << endl << endl <<endl<< t << " s" << endl << endl << endl;
    //cout << setw(15) << N[0] << "\t";
    for (size_t i = 1; i < SIZE-1; i++)
      {
      N[i] = N[i] + dN[i - 1];// -dN[i];//кол-во частиц в момент времени t
      if (t0 < period[i] / 10)
        dN[i] = N[i] / period[i] * log(2)*t0;//кол-во распавшихся частиц в момент времени t
      else
        dN[i] = N[i] * (1 - pow(2, -t0 / period[i]));

      
      if (dN[i]>N[i])
        dN[i] = N[i];
      N[i] = N[i] - dN[i];
      
     // cout <<setw(15)<< N[i] << "\t";
      }
    N[14] = N[14] + dN[13];
    N[0] = N[0] - dN[0];
    dN[0] = N[0] / period[0] * log(2)*t0;
    //cout << setw(15) << N[14] << "\t";
    }
  for (int i = 0; i < 15; i++)
    {
    f << setw(15) << N[i] << "\t" << dN[i] << endl;
    }
 
  system("pause");
  }