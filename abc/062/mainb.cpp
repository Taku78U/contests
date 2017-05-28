#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;

int main (void){
  uint h, w;
  cin >> h >> w;
  cin.ignore();
  char a[h][w];

  for (uint i = 0; i < h; i++){
    for (uint j = 0; j < w; j++){
      cin >> a[i][j];
    }
    cin.ignore();
  }

  for (uint i = 0; i < w+2; i++){
    cout << "#" << flush;
  }
  cout << endl;
  for(uint i = 0; i < h; i++){

    cout << '#' << flush;
    for (uint j = 0; j < w; j++){
      cout << a[i][j] << flush;
    }
    cout << '#' << endl;
  }
  for (uint i = 0; i < w+2; i++){
    cout << "#" << flush;
  }
  cout << flush;
  

  return 0;
}
