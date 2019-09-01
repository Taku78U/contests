#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main (){

  ll n, k;
  cin >> n >> k;
  cin.ignore();

  // 最初の目がa<kのとき
  // 連続で表にする回数はceil(log_2 n/k)

  double e;
  double p;
  double sum;

  // 最初からa>=Kの場合はそのまま勝つ

  ll limit;

  if(n >= k){
    sum = (n-k+1)/(double)n;
    limit = k - 1;
  } else {
    sum = 0;
    limit = n;
  }
  //cout << "sum = " << sum << endl;
  //cout << "n = " << n << endl;
  //cout << "k = " << k << endl;
  for(int i = 1; i <= limit; i++){
    e = ceil((log(k) - log(i)) / log(2));
    if(e > 0){
      p = pow(0.5, e);
      sum += p / n;
    }
    //cout << "e = " << e << endl;
  }

  cout << sum << endl;
  return 0;
}
