#include <bits/stdc++.h>
#define DBG
#define MAX_N 100000

using ll = long long;

ll penas[MAX_N] = {0};
ll acs[MAX_N] = {0};
bool ac_flgs[MAX_N];

using namespace std;

int main(){
  for (int i = 0; i < MAX_N; i++){
    ac_flgs[i] = false;
    acs[i] = 0;
    penas[i] = 0;
  }
  int n, m;
  cin >> n >> m;
  cin.ignore();

  if(m == 0){
    cout << 0 << " " << 0 << endl;
    return 0;
  }

  string s;
  int tmp;
  vector <int> p;
  vector <bool> r;

  for(int i = 0; i < m; i++){
    // デバッグ用
    cin >> tmp >> s;
    cin.ignore();
    p.push_back(tmp);
    if(s == "AC"){
      r.push_back(true);
    } else if(s == "WA"){
      r.push_back(false);
    } else {
#ifdef DBG
      cout << "i = " << i << ", Error! s = " << s << endl;
      return 0;
#endif
    }
    --tmp; // 0-origin
    if((s == "WA") && (ac_flgs[tmp] == false)){
      ++penas[tmp];
    } else if(s == "AC"){
      ac_flgs[tmp] = true;
    }
  }

  ll sum_ac = 0, sum_pena = 0;
  for (int i = 0; i < n; i++){
    if(ac_flgs[i] == true) ++sum_ac;
    if(ac_flgs[i] == true) sum_pena += penas[i];
  }

  cout << sum_ac << " " << sum_pena << endl;
  return 0;
}
    
