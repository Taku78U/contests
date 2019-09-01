#include <bits/stdc++.h>

using namespace std;

void warshall_fl(int c[][10]){
  int tmp;
  for (int k = 0; k < 10; k++){
    for (int i = 0; i < 10; i++){
      //if(i == j) continue;
      for(int j = 0; j < 10; j++){
        tmp = c[i][k] + c[k][j];
        if(c[i][j] > tmp) c[i][j] = tmp;
      }
    }
  }
}

int main (void) {
  int h, w;
  int c[10][10];
  cin >> h >> w;
  cin.ignore();
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      cin >> c[i][j];
    }
    cin.ignore();
  }
  warshall_fl(c);
  int tmp;
  unsigned long long sum = 0;
  int a[10] = {0};
  for (int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> tmp;
      if(tmp!=-1) {
        sum += c[tmp][1];
        a[tmp]++;
      }
    }
    cin.ignore();
  }

  cout << sum << endl;
/*
  for (int i = 0; i < 10; i++) cout << a[i] << "," << flush;
  cout << endl;
  for (int i = 0; i < 100; i++){
    cout << c[i] << "," << flush;
    if(i != 0 && i%10 == 9) cout << c[i] << endl;
  }
*/
  sum = 0;
  for(int i = 0; i < 10; i++){
    if(i == 1) continue;
    if(a[i] >= 0) sum += a[i] * c[i][1];
  }
  //cout << sum << endl;
  return 0;
}
      
