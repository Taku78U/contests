#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Axis
{
  ll x;
  ll y;

  bool operator<(const Axis &another) const
  {
    return (x == another.x) ? y < another.y : x < another.x; //年齢を比較
  };
  //2つのconstを付けないとコンパイルエラーになるので注意!!
};

int main(){

  int n;

  // すべての組み合わせの差を計算

  cin >> n;
  cin.ignore();

  ll tmpx, tmpy;
  Axis a[n];
  for (int i = 0; i < n; i++){
    cin >> tmpx >> tmpy;
    cin.ignore();
    a[i].x = tmpx;
    a[i].y = tmpy;
  }

  sort(a, a +n); // xの差を非負整数に
  
  // すべての組み合わせの差を計算
  int m = n * (n-1) / 2;
  Axis d[m];
  int ptr = 0;
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      tmpx = a[j].x - a[i].x; // 正
      tmpy = a[j].y - a[i].y;
      d[ptr].x = tmpx;
      d[ptr].y = tmpy;
      ++ptr;
    }
  }

  /*
  for (int i = 0; i < ptr; i++){
    cout <<"i = " << i << " p = " << d[i].x << " q = " << d[i].y << endl;
  }
  */
  

  //cout << endl;
  sort(d, d + ptr);

  int cnt = 1;
  int tmpcnt = 1;

  /*
  for (int i = 0; i < ptr; i++){
    cout <<"i = " << i << " p = " << d[i].x << " q = " << d[i].y << endl;
  }
  */
  
  for (int i = 0; i < ptr - 1; i++){
    if((d[i].x == d[i+1].x) && (d[i].y == d[i + 1].y)){
      //cout << "UPDATE" << endl;
      ++tmpcnt;
    } else {
      if(tmpcnt > cnt){
        //cout << "UPDATEC" << endl;
        cnt = tmpcnt;
      }
      tmpcnt = 1;
    }
  }

  if(n - cnt == 0){
    cout << 1 << endl;
    return 0;
  }

  cout << n - cnt << endl;

  return 0;
}
