#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

int main(){
  int a, b, h, m;

  cin >> a >> b >> h >> m;
  cin.ignore();

  long double theta_m, theta_h;
  theta_m = m / (long double)60 * M_PI * 2;
  theta_h = (h / (long double)12 + m / (long double) 12 / 60) * M_PI * 2;
  long double result = sqrtl((b * sin(theta_m) - a * sin(theta_h)) * (b * sin(theta_m) - a * sin(theta_h)) + (b * cos(theta_m) - a * cos(theta_h)) * (b * cos(theta_m) - a * cos(theta_h)));
  std::printf("%.100Lf\n", result);

  return 0;
}
    
  
