#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ll h, n;
  cin >> h >> n;
  cin.ignore();
  vector <ll> a;
  ll tmp;
  ll sum = 0;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    a.push_back(tmp);
    sum += tmp;
  }
  cin.ignore();
  
  if(h <= sum){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
