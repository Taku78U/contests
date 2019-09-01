#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main (void) {
  int n;
  cin >> n;
  cin.ignore();
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a, a + n);
  ll asum = 0;
  ll bsum = 0;
  bool sw = false;
  for (int i = 0; i < n; i++){
    if(sw==false){
      asum += a[n-1-i];
      sw = true;
    }else {
      bsum += a[n-1-i];
      sw = false;
    }
  }
  ll result;
  result = asum - bsum;
  cout << result << endl;
  return 0;
}
