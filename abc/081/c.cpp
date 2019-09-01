#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using ull = unsigned long long;

struct data_t{
  int n;
  int c;
  // 最後のconstを忘れると"instantiated from here"というエラーが出てコンパイルできないので注意
  bool operator<( const data_t& right ) const {
    return c < right.c;
  }
};

int main (void) {
  int k, n;

  cin >> n >> k;

  cin.ignore();

  int a[n];

  for (ll i = 0; i < n; i++) cin >> a[i];
  cin.ignore();

  // 個数を収める
  data_t c[200000];
  for (int i = 0; i < 200000; i++){
    c[i].n = i;
    c[i].c = 0;
  }

  for (int i = 0; i < n; i++){
    c[a[i]-1].c += 1;
  }
  //cout << c[0].c << endl;
  //cout << c[1].c << endl;
  //cout << c[4].c << endl;


  sort(c, c + 200000);

  // 0探し

  int ptr = 0;

  int cnt = 0;

  for (int i = 0; i < 200000; i++){
    if(c[i].c == 0){
      ptr++;
    }
    if(c[i].c > 0) cnt++;
  }

  //cout << ptr << endl;
  //cout << cnt << endl;

  int s = 0;
  s = cnt - k;
  if(s <= 0){
    cout << 0 << endl;
    return 0;
  }

  //cout << c[199997].n << endl;
  //cout << c[199998].n << endl;
  //cout << c[199999].n << endl;
  int sum = 0;
  for (int i = ptr; i < ptr + s; i++){
    sum += c[i].c;
  }

  cout << sum << endl;
  return 0;
}
  
