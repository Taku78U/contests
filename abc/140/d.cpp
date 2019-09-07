#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ll n, k;
  cin >> n >> k;
  cin.ignore();
  char s[n + 1];
  cin >> s;
  cin.ignore();
  s[n] = '\0';

  vector <ll> a;
  ll tmp = 1;

  // 今の幸福度は？

  ll kohuku = 0;
  ll kyokai = 0;
  for(int i = 1; i < n; i++){
    if(s[i] == s[i - 1]){
      ++kohuku;
    } else {
      ++kyokai;
    }
  }

  // 1回やるごとに境界は2つ減る
  if(k * 2 < kyokai){
    kohuku += k * 2;
    cout << kohuku << endl;
    return 0;
  }

  if(k * 2 >= kyokai){
    kohuku += kyokai;
    cout << kohuku << endl;
    return 0;
  }
  
  

  return 0;
}
