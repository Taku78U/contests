#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define STR_LEN 10

//組み合わせの数nCrを計算
ll calcNumOfCombination(int n, int r){
  ll num = 1;
  for(int i = 1; i <= r; i++){
    num = num * (n - i + 1) / i;
  }
  return num;
}

int main(){
  int n;
  cin >> n;
  cin.ignore();

  string tmp_s;
  char tmp_c[STR_LEN] = {0};
  vector <string> s;

  for (int i = 0; i < n; i++){
    cin >> tmp_c;
    sort(tmp_c, tmp_c + STR_LEN);
    tmp_s = tmp_c;
    //cout << tmp_s << endl;
    s.push_back(tmp_s);
    cin.ignore();
  }

  sort(s.begin(), s.end());
  ll cnt = 1;

  ll ans = 0;
  for(int i = 0; i < n - 1; i++){
    //cout << s[i] << endl;
    if(s[i] == s[i + 1]){
      ++cnt;
    } else if(cnt > 1){
      // これまでの数で組み合わせ数を計算
      ans += calcNumOfCombination(cnt, 2);
      cnt = 1; // 初期化
    } else {
      cnt = 1; // 初期o化
    }
  }

  // 最後はどう？
  if(cnt > 1){
    ans += calcNumOfCombination(cnt, 2);
  }

  cout << ans << endl;
    
  return 0;
}
  
