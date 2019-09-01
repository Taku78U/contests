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

  int limit;

  if(n >= k){
    sum = (n-k+1);
    limit = k - 1;
  } else {
    sum = 0;
    limit = n;
  }

  double e2[limit];
  //cout << "sum = " << sum << endl;
  //cout << "n = " << n << endl;
  //cout << "k = " << k << endl;
  for(int i = 1; i <= limit; i++){
    e = ceil((log(k) - log(i)) / log(2));
    if(e > 0){
      e2[i-1] = e;
      p = pow(0.5, e);
      //sum += p;
    }
    //cout << "e = " << e << endl;
  }

  sort(e2, e2 + limit);

  for (int i = 0; i < limit; i++){
    e2[i] = pow(0.5, e2[i]);
  }
  sum += accumulate(e2, e2 + limit, 0.0);
    

  cout << sum / n << endl;
  return 0;
}
