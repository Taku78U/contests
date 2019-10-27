#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int main(){
  int n;
  cin >> n;
  cin.ignore();
  vector <int> l;
  int tmp;
  for (int i = 0; i < n; i++){
    cin >> tmp;
    l.push_back(tmp);
  }

  sort(l.begin(), l.end());

  int ptr = 1; // ptr-1 と ptr の和で比較する
  int a[2] = {l[ptr - 1], l[ptr]};
  ll sum = 0;
  ll ans = 0;
  ll sum_a = 0;
  for (int i = 2; i < n;){
    sum_a = a[0] + a[1];
    //cout << "a = " << flush;
    //cout << a[0] << "," << a[1] << endl;
    //cout << "i = " << i << "l[i] = " << l[i] << endl;
    if(l[i] < sum_a){
      ++sum;
      ++i;
    } else {
      ans += sum;
      if(sum > 0){
        //--sum;
      } else {
        sum = 0;
      }
      ++ptr;
      a[0] = a[1];
      a[1] = l[ptr];
      if(ptr == i){
        ++i;
      }
    }
  }
  //cout << "ans = " << ans << endl;
  // 最後に残ったのはその総和を取る
  for (int i = 1; i <= sum; i++){
    ans += i;
  }
  cout << ans << endl;
  return 0;
}
