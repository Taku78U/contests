#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector<int> a, b, c, d;
vector<int> A(11, 1);
int ans;

void dfs(int i) {
  
  if (i == n + 1) {
    int calc = 0;
    for (int j = 0; j < q; j++) {
      if (A[b[j]] - A[a[j]] == c[j]) {
        calc += d[j];
      }
    }
    ans = max(ans, calc);
    return;
  }

  for (int j = A[i - 1]; j <= m; j++) {
    A[i] = j;
    dfs(i + 1);
  }
}

int main() {
  cin >> n >> m >> q;
  a.assign(q, 0);
  b.assign(q, 0);
  c.assign(q, 0);
  d.assign(q, 0);
  for (int i = 0; i < q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  dfs(1);
  cout << ans << endl;
  return 0;
}
