#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main (void){
  int n;
  cin >> n;
  cin.ignore();
  int s[n];
  ll sum = 0;
  priority_queue<int, vector<int>, greater<int>> q;
  for(int i = 0; i < n; i++){
    cin >> s[i];
    cin.ignore();
    sum += s[i];
    q.push(s[i]);
  }

  while(!q.empty()){
    if(sum % 10 != 0){
      cout << sum << endl;
      return 0;
    }
    if(q.top() % 10 != 0) sum -= q.top();
    q.pop();
  }
  cout << 0 << endl;
  return 0;
}
