#include <bits/stdc++.h>

using namespace std;

int main(void){
  int n;
  cin >> n;
  int w;
  int d;
  int t;

  for (int i = 1; i <= 3500; i++){
    for (int j = i; j <= 3500; j++){
      t = 4*i*j-n*j-n*i;
      if(t<=0) continue;
      d = (n*i*j) % t;
      if(d==0) {
        w = (n * i * j) / t;
        cout << i << ' ' << j << ' ' << w << endl;
        return 0;
      }
    }
  }
  return 0;
}
