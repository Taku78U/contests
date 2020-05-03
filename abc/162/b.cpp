#include <bits/stdc++.h>

using namespace std;

int n;
int main(){
  cin >> n;
  cin.ignore();


  long long sum = 0ll;
  for (int i = 1; i <= n; i++){
    if(i % 3 == 0) continue;
    if(i % 5 == 0) continue;
    sum += (long long) i;
  }

  cout << sum << endl;
  return 0;
}
