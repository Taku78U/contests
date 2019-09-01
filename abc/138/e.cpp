#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  char s[100000];
  string t;
  cin >> s;
  cin.ignore();
  sort(s, s + strlen(s));
  cin >> t;
  cin.ignore();

  vector <int> lst[('z' - 'a') + 1];

  for(int i = 0; i < strlen(s); i++){
    lst[(s[0] - 'a')].push_back(i);
  }

  ll ans = 0;
  int i = 0;
  int dif = 0;
  int ptr = 0;
  int idx = 0;
  int pre_idx = -1;
  vector <int> tmp;
  vector <int> tmp2;

  // 1回目
  idx = t[i] - 'a';
  if(lst[idx].size() == 0){ // 存在なし
    cout << -1 << endl;
    return 0;
  }
  tmp2 = lst[idx];
  ans += tmp2[0] + 1;
  ptr = 0;
  
  while(1){
    idx = t[i] - 'a';
    if(lst[idx].size() == 0){ // 存在なし
      cout << -1 << endl;
      return 0;
    }
    if(i >= t.size()){ // t終端まで
      break;
    }
    if((idx == pre_idx) && (ptr >= lst[idx].size() - 1)){
      tmp = lst[idx];
      ans += (strlen(s) - tmp[ptr] - 1) + (tmp[0] + 1);
      ptr = 0;
    } else if(idx == pre_idx){
      tmp = lst[idx];
      ans += tmp[ptr + 1] - tmp[ptr];
      ++ptr;
    } else {
      tmp = lst[pre_idx];
      tmp2 = lst[idx];
      if(tmp2[0] < tmp[ptr]){
        ans += (strlen(s) - tmp[ptr] - 1) + (tmp2[0] + 1);
      } else {
        ans += tmp2[0] - tmp[ptr];
      }
      ptr = 0;
    }
    pre_idx = idx;
    ++i;
  }
  cout << ans << endl;
  return 0;
  
}
  
