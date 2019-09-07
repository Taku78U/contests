#include <bits/stdc++.h>
#define MAXN = 100005

using namespace std;

using ll = long long;

const ll INF = LLONG_MAX;



vector <ll> dista [MAXN];
vector <ll> distb [MAXN];
void djs(ll* cost, 

int main(void){
  ll n, m, s, t;
  cin >> n >> m >> s >> t;
  cin.ignore();
  s--;
  t--;
  ll u[m], v[m], a[m], b[m];
  for (ll i = 0; i < n; i++){
    for (ll j = 0; j < n; j++){
      dista[i][j] = INF;
      distb[i][j] = INF;
    }
  }
  
  for (ll i = 0; i < m; i++){
    cin >> u[i] >> v[i] >> a[i] >> b[i];
    u[i]--;
    v[i]--;
    cin.ignore();
    dista[u[i]][v[i]] = a[i];
    distb[u[i]][v[i]] = b[i];
    dista[v[i]][u[i]] = a[i];
    distb[v[i]][u[i]] = b[i];
  }

  // 両替は1駅だけ
  // s->i 円 t->i スヌーク

  ll costa[n];
  for(ll i = 0; i < n; i++){
    costa[i] = INF;
  }
  ll costb[n];
  for(ll i = 0; i < n; i++){
    costb[i] = INF;
  }

  // ダイクストラで全駅へのコストを求める
  for(ll i = 0; i < n; i++){
    djs(*costa, s, i);
  }
  for(ll j = 0; j < n; j++){
    djs(*costb, t, j);
  }

  // indexとまとめて処理ー＞あとで
  return 0;
}
