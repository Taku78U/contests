#include <bits/stdc++.h>

using namespace std;

int main(){
  int a, b, c;

  cin >> a >> b >> c;

  cin.ignore();

  int ans;

  if(b + c > a){
    ans = b + c - a;
  } else {
    ans = 0;
  }
  cout << ans << endl;
                 return 0;
}
