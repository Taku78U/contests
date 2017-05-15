#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

int main (void){
  uint n, m;
  cin >> n >> m;
  cin.ignore();
  uint a[m], b[m];
  uint i;
  for(i=0;i<m;i++){
    cin >> a[i] >> b[i];
    cin.ignore();
  }

  // 全数カウント
  uint cnt[n] = {0};
  for (i=0;i<m;i++){
    cnt[a[i]-1]++;
    cnt[b[i]-1]++;
  }

  for(i=0;i<n;i++){
    cout << cnt[i] << endl;
  }
  return 0;
}
  
