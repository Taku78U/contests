#include <bits/stdc++.h>

using namespace std;

using ll = long long;

static const ll MOD = 1000000007LL;

int main(){
  string s;
  cin >> s;
  cin.ignore();

  int n;

  n = strlen(s);

  // DPテーブル
  // dp[i][j]は、i桁目までの余りがjであるものの数を表す
  // 1: 桁数
  ll dp[n + 1][13];

  dp[0][0] = 1;

  int c; // s[i]を数値に変換、?の場合は-1
  for (int i = 0; i < n; i++){
    if(s[i] == '?'){
      c = -1;
    } else {
      c = s[i] - '0';
    }

    for(int j = 0; j < 10; j++){
      if((c == -1) && (c == j)){
        for(int k = 0; k < 13; k++){
          dp[i+1][(k * 10 + j) % 13] += dp[i][k];
        }
      } else {
        continue;
      }
    }
    for (int j = 0; j < 13; j++){
      dp[i+1][j] %= MOD;
    }
  }

  ll res = dp[n][5];
  cout << res << endl;
  return 0;
}
