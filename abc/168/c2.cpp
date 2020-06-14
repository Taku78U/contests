#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

int main(){
  int a, b, h, m;

  cin >> a >> b >> h >> m;
  cin.ignore();

  long double theta_d;
  theta_d = m / (long double)60 - (h / (long double)12 + m  / (long double) 60 / 12);
  if(abs(theta_d) < numeric_limits<long double>::epsilon()){
    cout << 0 << endl;
    return 0;
  }
  theta_d *= 2 * PI;
  
  long double sinb = b * sin(theta_d);
  long double cosb = b * cos(theta_d);
  long double result = sqrt(sinb * sinb + (cosb - a) * (cosb - a));
  std::printf("%.100Lf\n", result);

  return 0;
}
    
  
