#include <bits/stdc++.h>

using namespace std;

using ll = long long;

static const ll MAX_NUM = 200000;

int main(){
  ll n, k;
  vector <ll> a;
  ll tmp;
  cin >> n >> k;
  cin.ignore();

  for(ll i = 0; i < n; i++){
    cin >> tmp;
    a.push_back(tmp);
  }

  ll ext[MAX_NUM];
  memset(ext, 0, sizeof(ext));

  vector <ll> s;
  ll e = 0;

  ll loc;

  for(ll i = 0; i < k;){
    for(ll j = 0; j < n; j++){
      loc = a[j] - 1;
      if(ext[loc] == 0){
        s.push_back(a[j]);
        ++e;
        ext[loc] = e;
        //cout << "p1" << endl;
        //for (ll i = 0; i < s.size(); i++){
        //  cout << s[i] << " " << flush;
        //}
        //cout << endl;
      } else {
        // その位置までvectorから削除
        s.erase(s.begin() + (ext[loc] - 1), s.end());
        memset(ext, 0, sizeof(ext));
        
        //cout << "p2" << endl;
        //for (ll i = 0; i < s.size(); i++){
        //  cout << s[i] << " " << flush;
        //}
        //cout << endl;
        e = 0;
        for(ll m = 0; m < s.size(); m++){
          loc = s[m] - 1;
          ext[loc] = m + 1;
        }
        e = s.size();
      }
    }

    if(s.empty() == true){
      ll t = k % (i + 1);
      //cout << "i = " << i << endl;
      i = k - t;
      //cout << "t = " << t << endl;
      //cout << "next i = " << i << endl;
    } else {
      ++i;
    }
  }


  for (ll i = 0; i < s.size(); i++){
    cout << s[i] << " " << flush;
  }
  cout << endl;
  return 0;
}
        
