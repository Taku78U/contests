#include <bits/stdc++.h>

//#define DBG

using namespace std;
using ll = long long;

ll n, q;
vector<ll> c;
vector<string> svec;

bool sell_single(ll x, ll a){
  if(c[x] < a) return true;
  c[x] -= a;
  return false;
}

bool sell_odd_check(ll a){
  for(ll i = 0; i < n; i+= 2){
    if(c[i] < a) return true;
  }
}  

bool sell_odd(ll a){
  for(ll i = 0; i < n; i+= 2){
    if(c[i] < a) return true;
  }
  for(ll i = 0; i < n; i+= 2){
    c[i] -= a;
  }
  return false;
}
  
bool sell_all(ll a){
  for(ll i = 0; i < n; i+= 1){
    if(c[i] < a) return true;
  }
  for(ll i = 0; i < n; i+= 1){
    c[i] -= a;
  }
  return false;
}
  

int main(){
  cin >> n;
  cin.ignore();
  ll tmp;
  for(ll i = 0; i < n; i++){
    cin >> tmp;
    c.push_back(tmp);
  }
  cin.ignore();

  ll q;
  cin >> q;
  cin.ignore();

  ll ans = 0;
  ll ans_add = 0;

  int cmd, x, a;
  bool impos_cmd1 = false;
  bool impos_cmd2 = false;
  bool impos_cmd3 = false;
  ll all_min = LLONG_MAX;
  ll odd_min = LLONG_MAX;
  ll odd_stack = 0;
  ll all_stack = 0;
  for(ll i = 0; i < q; i++){
    cin >> cmd;
    if(cmd == 1){
      cin >> x >> a;
      #ifdef DBG
      printf("CMD = 1, x = %d, a = %d\n", x, a);
      #endif
      --x;
      impos_cmd1 = sell_single(x, a);
      if(impos_cmd1 == false){
        if(x%2 == 0){
          if(odd_min > c[x]) odd_min = c[x];
        }
        if(all_min > c[x]) all_min = c[x];
        ans += a;
    } else if(cmd == 2){
      cin >> a;
      #ifdef DBG
      printf("CMD = 2, a = %d\n", a);
      #endif
      impos_cmd2 = sell_odd(a);
      ans_add = a * (n / 2 + n % 2);
      if(impos_cmd2 == false) ans += ans_add;
#ifdef DBG
      else printf("LACK\n");
#endif
    } else if(cmd == 3){
      cin >> a;
      #ifdef DBG
      printf("CMD = 3, a = %d\n", a);
      #endif
      impos_cmd3 = sell_all(a);
      if(impos_cmd3 == false) ans += a * n;
      else {
        impos_cmd2 = true; // cmd3ができないときはcmd2もムリ
#ifdef DBG
        printf("LACK\n");
#endif
      }
    } else {
      cout << "Error, i = " << i << endl;
      return 0;
    }
    cin.ignore();
  }
  cout << ans << endl;
  return 0;
}
  
