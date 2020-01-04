#include <bits/stdc++.h>
//#define DBG

using namespace std;

using ll = long long;

int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  cin.ignore();

  ll tmp;
  if(b < a){
    tmp = b;
    b = a;
    a = tmp;
  }

  //以下、a<b

  ll d = b - a;

  // 距離が偶数ならその半分が最小の回数

  ll ans;
  if(d % 2 == 0){
    ans = d / 2;
    cout << ans << endl;
    return 0;
  }

  // 1に寄った場合
  ll a_tmp, b_tmp;
  ll cnt1 = a - 1; // まずaが1に行く
  a_tmp = 1;
  b_tmp = b - (a - 1);

  // aが1に留まる
  --b_tmp;
  ++cnt1;
#ifdef DBG
  cout << "1" << endl;
  cout << "a_tmp = " << a_tmp << " " << flush;
  cout << "b_tmp = " << b_tmp << " " << endl;
#endif
  // b_tmpがすでに1であれば？
  if(b_tmp == 1){
  } else {
    cnt1 += (b_tmp - a_tmp) / 2;
  }
    
  // Nに寄った場合
  //ll a_tmp, b_tmp;
  ll cnt2 = n - b; // まずbがnに行く
  b_tmp = n;
  a_tmp = a + (n - b);

  // bがnに留まる
  ++a_tmp;
  ++cnt2;
#ifdef DBG
  cout << "N" << endl;
  cout << "a_tmp = " << a_tmp << " " << flush;
  cout << "b_tmp = " << b_tmp << " " << endl;
#endif
  // b_tmpがすでに1であれば？
  if(b_tmp == 1){
  } else {
    cnt2 += (b_tmp - a_tmp) / 2;
  }

  if(cnt1 < cnt2){
    ans = cnt1;
  } else {
    ans = cnt2;
  }

  cout << ans << endl;
  return 0;
}

  
