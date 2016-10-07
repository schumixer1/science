#include <iostream>
#include <cmath>
#include<iomanip>
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
  double dNInDt[SIZE]{};
  N[0] = massOfUran*Na / molarMassofUran;
  cout << N[0];
  int time = 10;// 1 * 60 * 60 * 24;
  dNInDt[0] = N[0] / (period[0] * log(2));

  for (int t{}; t <= time; t++)
    {
    cout << endl << endl <<endl<< t << " s" << endl << endl << endl;
    for (size_t i = 1; i < SIZE; i++)
      {
      
      N[i]+=  dNInDt[i - 1];// -dNInDt[i];
      dNInDt[i] = N[i] / (period[i] * log(2));
      N[i] -= dNInDt[i];
      cout <<setw(15)<< N[i] << "\t";
      }
    N[0] = N[0] - dNInDt[0];
    dNInDt[0] = N[0] / (period[0] * log(2));
    }
  system("pause");
  }