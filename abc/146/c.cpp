#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll keta_n(ll n){
  if (n < 10){
    return 1;
  }
  ll rtn = 0;
  while(n > 0){
    rtn += 1;
    n /= 10;
  }
  return rtn;
}

int main(){
  ll a, b, x;
  cin >> a >> b >> x;
  cin.ignore();

  if(a > x || b > x){
    cout << 0 << endl;
    return 0;
  }

  // 許容される桁数
  ll maxdn = x / b; // dn最大値
  if(maxdn > 10){ // 範囲的に10までしかありえない
    maxdn = 10;
  }

  ll maxn = x / a; // n最大値

  ll maxn_dn = 1; // dn最大値から求めたn最大値
  for(ll i = 0; i < maxdn - 1; i++){
    maxn_dn *= 10;
  }

  if(maxn > maxn_dn){
    maxn = maxn_dn;
  }

  ll tmp_x;
  tmp_x = a * maxn + b*keta_n(maxn);
  /*if(x > tmp_x){
    for (ll i = maxn + 1; i <= 1000000000; i++){
      tmp_x = a * i + b*keta_n(i);
      if(tmp_x > x){
        cout << i - 1 << endl;
        return 0;
      }
    }
    } else {*/
  //cout << "maxn = " << maxn<< endl;
  //for(ll i = maxn; i >= 0; i--){
  //  tmp_x = a * i + b*keta_n(i);
  //  if(x >= tmp_x){
  //    cout << i << endl;
  //    return 0;
  //  }
  //}

  // にぶたん

  ll lefta = 1, righta = maxn;
  ll mid;
  mid = maxn;
  tmp_x = a * mid + b * keta_n(mid);
  if(x == tmp_x){
    cout << mid << endl;
    return 0;
  }
  while(lefta < righta){
    mid = (lefta + righta) / 2;
    //cout << "lefta = " << lefta << endl;
    //cout << "righta = " << righta << endl;
    //cout << "mid = " << mid << endl;
    cout << endl;
    tmp_x = a * mid + b * keta_n(mid);
    if(x == tmp_x){
      //cout << "1" << endl;
      cout << mid << endl;
      return 0;
    }
    if(x > tmp_x){
      lefta = mid + 1;
    }
    if(x < tmp_x){
      righta = mid;
    }
  }

  mid = lefta;
  tmp_x = a * mid + b * keta_n(mid);
  if(x >= tmp_x){
    //cout << "1" << endl;
    //cout << "Final" << endl;
    cout << mid << endl;
    return 0;
  } else {
    cout << mid - 1 << endl;}
  return 0;
}
