#include <bits/stdc++.h>

using namespace std;

int main (void){
  int n;
  cin >> n;
  cin.ignore();

  int a[n];
  int tmp;

  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a, a + n);

  unsigned short color = 0;
  bool ex[8] = {0};
  int fs = 0;

  for (int i = 0; i < n; i++){
    while (color < 8){
      if(color * 400 <= a[i] && a[i] < (color + 1) * 400){
        ex[color] = true;
        break;
      } else color++;
    }
    if(color == 8){
      fs++;
      continue;
    }
  }

  int nc = 0;
  for (int i = 0; i < 8; i++){
    if(ex[i]) nc++;
  }

  if (nc == 0 && fs != 0) cout << 1 << endl;
  else cout << nc << " " << flush;
  /*
  if(nc + fs >= 8) cout << 8 << endl;
  else cout << nc + fs << endl;
  */
  cout << nc + fs << endl;
  return 0;
}
