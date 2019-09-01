#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  cin.ignore();

  int l[n] = {0};

  int cnt = 1;
  int dist = 0;

  for (int i = 0; i < n; i++){
    cin >> l[i];
    dist += l[i];
    if(dist <= x){
      ++cnt;
    } else {
      break;
    }
  }

  cout << cnt << endl;
  return 0;
}
