#include <bits/stdc++.h>

using namespace std;

long long n, m;
vector <int> a;
int main(){
  int tmp;
  cin >> n >> m;
  cin.ignore();
  long long sum = 0;
  for (int i = 0; i < m; i++){
    cin >> tmp;
    sum += tmp;
  }

  if(n < sum){
    cout << "-1" << endl;
    return 0;
  }
  cout << (n - sum) << endl;
  return 0;
}
