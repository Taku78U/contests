#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main (void){
  ll n, a, b;
  cin >> n >> a >> b;
  cin.ignore();

  vector<ll> h;
  ll tmp;

  for (int i = 0; i < n; i++){
    cin >> tmp;
    cin.ignore();
    h.push_back(tmp);
  }

  // 最初から一体だけ
  if(n == 1){
    cout << h[0] / a + 1 << endl;
    return 0;
  }

  sort(h.begin(), h.end());

  ll c = a - b;

  ll lb = 0; // 絶対に条件を満たさない
  ll ub = h.back() / b + (h.back() % b); // 絶対に条件を満たす
  ll mid; // この値について「満たすかどうか」をチェックする
  ll csum = 0; // 追加攻撃回数
  ll thp; // 各モンスター残りHP

  ll lp_dbgcnt = 0;
  while(ub - lb >= 2){
    //cout << ub << " " << lb << endl;
    csum = 0;
    mid = (lb + ub) / 2;

    // まず全モンスターにmid回bのダメージを与える
    // 次に各モンスターに合計mid回の追加攻撃
    for(auto itr = h.begin(); itr != h.end(); itr++){
      thp = (*itr - b * mid);
      csum += (thp <= 0) ? 0 : thp / c + (thp % c != 0); 
    }
    if(csum <= mid) ub = mid;
    else lb = mid;

    lp_dbgcnt++;
    /*
    if(lp_dbgcnt == 1000){
      cout << "ERR" << endl;
      exit(1);
    }
    */
  }

  cout << ub << endl;

  return 0;
}
