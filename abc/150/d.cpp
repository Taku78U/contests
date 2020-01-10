#include <bits/stdc++.h>
//#define DBG
using namespace std;

int gcd(long long a, long long b){
  long long r = b;
  long long tmp;
  while(r > 0){
    tmp = a % r;
    a = r;
    r = tmp;
  }
  return a;
}

int lcm(long long a, long long b){
  return a * b / gcd(a, b);
}

int nlcm(vector<int> a){
  long long l = 1;
  for(int i = 0; i < a.size(); i++){
    l = lcm(l, a[i]);
  }
  return l;
}

int main(){
  int n, m;
  cin >> n >> m;
  cin.ignore();

  vector <int> a;
  int tmp;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    if(tmp %2 == 1){ // 奇数ならもうアウト
      cout << 0 << endl;
      return 0;
    }
    a.push_back(tmp/2);
  }

  sort(a.begin(), a.end());

  long long d = nlcm(a);
  #ifdef DBG
  cout << "nlcm = " << d << endl;
  #endif

  for(int i = 0; i < n; i++){
    if((d / a[i]) % 2 == 0){
      cout << 0 << endl;
      return 0;
    }
  }

  long long ans = m / d;
  if(ans % 2 == 0) {
    cout << ans / 2 << endl;
    return 0;
  } else {
    cout << (ans / 2 + 1) << endl;
    return 0;
  }
  return 0;
}
  
