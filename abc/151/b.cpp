#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, k, m;
  cin >> n >> k >> m;
  cin.ignore();

  vector <int> a;
  int tmp;
  int sum = 0;
  for(int i = 0; i < n - 1; i++){
    cin >> tmp;
    sum += tmp;
    a.push_back(tmp);
  }
  cin.ignore();

  int mk_sum = m * n;
  
  int a_n = mk_sum - sum;
  if(a_n < 0) a_n = 0;

  if(k < a_n){
    cout << -1 << endl;
  } else {
    cout << a_n << endl;
  }

  return 0;
}
