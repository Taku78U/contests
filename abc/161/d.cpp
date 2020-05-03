#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll k;

vector <ll> arr;
vector<ll> ruiseki_arr;

void print_arr(){
  cout << "arr = " << flush;
  for(auto it = arr.begin(); it != arr.end(); it++){
    cout << *it << " " << flush;
  }
  cout << endl;
  cout << "ruiseki_arr = " << flush;
  for(auto it = ruiseki_arr.begin(); it != ruiseki_arr.end(); it++){
    cout << *it << " " << flush;
  }
  cout << endl;
  return;
}
int main(){
  cin >> k;
  cin.ignore();

  ll tmp = 9;
  ll ruiseki = 9;

  while(ruiseki <= 100000){
    arr.push_back(tmp);
    ruiseki_arr.push_back(ruiseki);
    tmp *= 3;
    ruiseki += tmp;
  }
  print_arr();
  

  ll ans;
  int keta, suf;
  if(k < 10){
    cout << k << endl;
    return 0;
  }

  for(int i = ruiseki_arr.size() - 1; i >= 0; i--){
    if(ruiseki_arr[i] < k){
      keta = i + 2;
      break;
    } else if(ruiseki_arr[i] == k){
      for(int j = 0; j <= i + 1; j++){
        cout << 9 << flush;
      }
      cout << endl;
      return 0;
    }
  }
  int arr_suf = keta - 2;
  ll dif = k - ruiseki_arr[arr_suf];
  ll mod = k;
  ll div = arr[keta-2];
  vector <ll> num;
  div = 3;
  while(div <= arr[arr_suf]){
    num.push_back(dif % 3);
    dif /= 3;
    div *= 3;
  }
  
  for(int i = 0; i < num.size(); i++){
    cout << num[i] << " " << flush;
  }
    cout << endl;
    
  return 0;
}
