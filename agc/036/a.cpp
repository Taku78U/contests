#include <bits/stdc++.h>

using namespace std;

using ll = long long;

static const ll MAX_P = 1000000000;

int main(){
  ll s;
  cin >> s;
  cin.ignore();

  // まず何桁


  // 10^9以下なら、X3=Y3=0, X2=Y1=0, Y2=1, X1=Sとでもすればよい
  if(s <= MAX_P){
    cout << s << " 0 0 1 0 0" << endl;
    return 0;
  }

  // それ以上なら、とりあえず10^9で割ってみる

  ll a, b;
  a = s / MAX_P;
  b = s % MAX_P;

  if(b == 0){ // X1 = 10^9, Y1 = X2 = 0, Y2 = a
    cout << MAX_P << " 0 0 " << a << " 0 0" << endl;
    return 0;
  }

  ll x1 = MAX_P;
  ll x3 = 0;
  ll y3 = 0;
  ll y2 = a + 1;

  ll y1, x2; // こいつらだけ未定
  ll sub_s = MAX_P - b;
  
  x2 = 1; // 勝手に仮定
  y1 = sub_s;

  // x1 y1 x2 y2 x3 y3
  cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
  
  
  
  return 0;
}
