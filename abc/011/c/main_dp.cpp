#include <bits/stdc++.h>

using namespace std;

typedef unsigned short us;

bool ng (int n, int n1, int n2, int n3){
  return (n == n1) || (n == n2) || (n == n3);
}

int main (void){
  int n, n1, n2, n3;

  cin >> n;
  cin.ignore();
  cin >> n1;
  cin.ignore();
  cin >> n2;
  cin.ignore();
  cin >> n3;

  int dp[n+1] = {0};

  int i, j;
  for (i = n; i >= 0; i--){
    if(ng(i, n1, n2, n3)) continue;
    if ((i != n) & (dp[i] == 0)){
      cout << "NO" << endl;
      return 0;
    }
    for (j = 1; j <= 3; j ++){
      if (dp[i-j] == 0) dp[i-j] = dp[i]+1;
      else dp[i - j] = min(dp[i] + 1, dp[i - j]);
    }
  }
  for (i = 0;i<=n;i++)
    cout << dp[i] << "," << flush;
  cout << endl;
  if(dp[0] <= 100) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
