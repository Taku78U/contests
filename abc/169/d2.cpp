#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n;
  cin >> n;
  long long sq_n = sqrtl(n) + 1;
  long long cnt = 0;
  if(n == 1){
    cout << 0 << endl;
    return 0;
  }
  for(long long i = 2; i <= sq_n; i++){
    if(n % i == 0){
      n /= i;
      ++cnt;
    }
  }
  if(cnt == 0) ++cnt;
  cout << cnt << endl;
  return 0;
}
