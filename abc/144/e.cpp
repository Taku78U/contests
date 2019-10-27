#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Info{
  ll a;
  ll f;
  ll af;

  bool operator<(const Info &another) const
  {
    return af < another.af;//積で比較
  };
};

int main(){
  ll n, k;
  cin >> n >> k;
  cin.ignore();

  vector<ll> a_arr;
  vector<ll> f_arr;
  ll tmp;
  for(ll i = 0; i < n; i++){
    cin >> tmp;
    a_arr.push_back(tmp);
  }
  cin.ignore();
  for(ll i = 0; i < n; i++){
    cin >> tmp;
    f_arr.push_back(tmp);
  }
  cin.ignore();

  Info tmp_nfo;
  sort(a_arr.begin(), a_arr.end());
  sort(f_arr.begin(), f_arr.end());

  priority_queue <Info> pqInfo;

  for(ll i = 0; i < n; i++){
    tmp_nfo.a = a_arr[i];
    tmp_nfo.f = f_arr[n - 1 - i];
    tmp_nfo.af = a_arr[i] * f_arr[n - 1 - i];
    pqInfo.push(tmp_nfo);
  }

  // でかいものを最大k回やる
  for(ll i = 0; i < k; i++){
    tmp_nfo = pqInfo.top();
    if(tmp_nfo.a > 0){
      --(tmp_nfo.a);
      tmp_nfo.af = tmp_nfo.a * tmp_nfo.f;
      pqInfo.pop();
      pqInfo.push(tmp_nfo);
    } else { // すでにコストゼロ
      cout << 0 << endl;
      return 0;
    }
  }
  tmp_nfo = pqInfo.top();
  cout << tmp_nfo.af << endl;
  return 0;
}
