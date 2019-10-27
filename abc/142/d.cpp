#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define MAX_NUM 1000000

int main(){
  ll a, b;
  cin >> a >> b;
  cin.ignore();

  ll tmp;
  if(a < b){
    tmp = a;
    a = b;
    b = tmp;
  }

  if(a == 1){ // 片方が1なら、公約数は1しかない
    cout << 1 << endl;
    return 0;
  }

  ll r;
  /* ユークリッドの互除法 */
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }

  // このループが終わったときの最大公約数は b

  if(b == 1){ // 最大公約数がb
    cout << 1 << endl;
    return 0;
  }

  //cout << "b = " << b << endl;

  //1は確実に公約数
  int cnt = 1;

  // bの素因数分解

  ll sqrt_b = ceil(sqrt(b));
  bool flag = false;
  while(b % 2 == 0){
    flag = true;
    b /= 2;
  }
  if(flag == true){
    ++cnt;
  }
  ll i = 3;
  for (i = 3; i <= sqrt_b; i+=2){
    flag = false;
    while(b % i == 0){
      flag = true;
      b /= i;
    }
    if(flag == true){
      ++cnt;
    }
  }
  // さいごに残ったb
  if(b > 1){
    cout << ++cnt << endl;
  } else {
    cout << cnt << endl;
  }
  return 0;
}
