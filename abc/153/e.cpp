#include <bits.stdc++.h>
#define DBG

using namespace std;

struct Magic{
  ll a; // ダメージ
  ll b;
};

// DPテーブル
// 1:攻撃回数
// 2: ダメージ
// 3: 魔力
ll dp[10000+1];
vector <ll> a, b;

using ll = long long;

int main(){

  // dp初期化
  for(int i = 0; i < 10000+1; i++){
    for(int j = 0; j < 10000+1; j++){
      dp[i][j] = LLONG_MAX;
    }
  }

  dp[0] = 0;

  // おなじ魔法は何度でも使える。
  ll h, n;
  cin >> h >> n;
  cin.ignore();
  ll tmp_a, tmp_b;
  for(ll i = 0; i < n; i++){
    cin >> tmp_a >> tmp_b;
    a.push_back(tmp_a);
    b.push_back(tmp_b);
    cin.ignore();
  }

  ll suf = 0;
  for(ll i = 0; i <= h; i++){ // h回の攻撃で死ぬ
    for(ll j = 0; j < n; j++){
      if(i + a[j] > h) suf = h;
      else suf = i + a[j];
      if(dp[suf] > dp[i] + b[j]){
        dp[suf] = dp[i] + b[j];
      }
    }
  }

  
  return 0;
}
