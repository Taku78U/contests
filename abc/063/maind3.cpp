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
    

  // 体力が大きい奴を優先的に消す！
  priority_queue <ll> q;
  for (auto itr = h.begin(); itr != h.end(); itr++){
    q.push(*itr);
  }

  ll max = q.top();
  ll cnt = 0;
  ll tmp_cnt = 0;
  while(!q.empty()){
    max = q.top() - b * cnt;
    if(max <= 0) break;
    tmp_cnt = max/a+(max%a!=0);
    cnt += tmp_cnt;
    q.pop();
  }
  cout << cnt << endl;
  return 0;
}
