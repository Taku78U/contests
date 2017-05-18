#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1LL << 50;

//const ll INF = MAX_LONG_LONG;

void bellmanford_k(int* a, int* b, int* c, ll* d, int m, int n){
  int i;
  d[0] = 0;
  for (i=1;i<n;i++){
    d[i] = INF;
  }

  int loop;
  for (loop = 0; loop < n - 1; loop++){
    for (i = 0; i < m; i++){
      if (d[a[i] - 1] == INF) continue;
      //cout << "i = " << i << endl;

      if(d[a[i] - 1] + c[i] < d[b[i] - 1]){
        /*cout << "Updated. a[i]-1 = " << a[i] - 1 << ", b[i] - 1 = " <<
            b[i] - 1 << ", c[i] = " << c[i] << ", d[a[i] - 1] = " << d[a[i] - 1] <<
            ", d[b[i] - 1] = " << d[b[i] - 1] << endl;*/
        d[b[i] - 1] = d[a[i] - 1] + c[i];
      }
    }
  }
  return;
} 

void bellmanford_b(int* a, int* b, int* c, ll* d, int m, int n, bool* negative){
  int i;

  int loop;
  for (loop = 0; loop < n; loop++){
    for (i = 0; i < m; i++){
      if (d[a[i] - 1] == INF) continue;

      //cout << "i = " << i << endl;

      if(d[a[i] - 1] + c[i] < d[b[i] - 1]){
        /*
        cout << "Updated. a[i]-1 = " << a[i] - 1 << ", b[i] - 1 = " <<
            b[i] - 1 << ", c[i] = " << c[i] << ", d[a[i] - 1] = " << d[a[i] - 1] <<
            ", d[b[i] - 1] = " << d[b[i] - 1] << endl;
        d[b[i] - 1] = d[a[i] - 1] + c[i];
        */
        negative[b[i] - 1] = true;
      }

      if(negative[a[i] - 1]) negative[b[i] - 1] = true;
    }
  }
  return;
}

int main (void){
  int n, m;
  cin >> n >> m;
  cin.ignore();

  int a[m], b[m], c[m];
  int i;

  // 最良スコア→最短経路
  for (i=0;i<m;i++){
    cin >> a[i] >> b[i] >> c[i];
    cin.ignore();
    c[i] = -c[i];
  }

  ll d[n];

  bellmanford_k(a, b, c, d, m, n);

  ll ans = -d[n-1];

  bool negative[n];
  for(i = 0; i < n; i++) negative[i] = false;

  //cout << "b" << endl;
  bellmanford_b(a, b, c, d, m, n, negative);

  if(negative[n-1]) cout << "inf" << endl;
  else cout << ans << endl;

  return 0;
}
