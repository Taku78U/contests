#include <bits/stdc++.h>

using namespace std;

int main (void){
  int deg, dis;

  cin >> deg >> dis;

  int v;
  v = dis * 10 / 60;
  if ((v >= 0) && (v <= 2)){
    cout << 'C' << ' ' << 0 << endl;
    return 0;
  }

  string s;
  if((113 <= deg) && (deg < 338)) {
    s = "NNE";
  } else if ((338 <= deg) && (deg < 563)){
    s = "NE";
  } else if ((563 <= deg) && (deg < 788)){
    s = "ENE";
  } else if ((788 <= deg) && (deg < 1013)){
    s = "E";
  }
  
