#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using uint = unsigned int;

int main (void){
  int n;

  cin >> n;
  cin.ignore();

  ll a[3 * n] = {0};

  for(int i = 0; i < 3 * n; i++){
    cin >> a[i];
  }
  cin.ignore();

  vector <ll> sumf, suml;

  ll sumf_tmp = 0, suml_tmp = 0;

  for (int i = 0; i < n; i++){
    sumf_tmp += a[i];
    suml_tmp += a[2 * n + i];
  }

  sumf.push_back(sumf_tmp);
  suml.push_back(suml_tmp);

  priority_queue<ll, vector<ll>, greater<ll>> qf;
  priority_queue<ll> ql;
  ll tmp;
  for (int i = 0; i < n; i++){
    qf.push(a[i]);
  }
  for (int i = 2 * n; i < 3 * n; i++){
    ql.push(a[i]);
  }
  
  for (int i = n; i < 2 * n; i++){
    tmp = a[i];
    //cout << "i = " << i << " tmp = "  << tmp << endl;
    //cout << "sumf_tmp = " << sumf_tmp << endl;
    sumf_tmp = sumf_tmp - qf.top() + tmp;
    qf.pop();
    sumf.push_back(sumf_tmp);
  }

  for (int i = 2 * n - 1; i >= n; i--){
    tmp = a[i];
    //cout << "i = " << i << " tmp = "  << tmp << endl;
    //cout << "suml_tmp = " << suml_tmp << endl;
    suml_tmp = suml_tmp - ql.top() + tmp;
    ql.pop();
    suml.push_back(suml_tmp);
  }

  ll max_dif = 0, tmp_dif = 0;
  auto itrl = suml.back();
  for (int i = 0; i <= n; i++){
    tmp_dif = sumf[i] - suml[n - i];
    //cout << " itrf = " << *itrf << ", itrl = " << *itrl << endl;
    if(i == 0) max_dif = tmp_dif;
    else if (max_dif < tmp_dif) max_dif = tmp_dif;
    //itrl--;
  }

  cout << max_dif << endl;;

  return 0;
}
  
