#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

struct record{
  ull a;
  ull b;

  bool operator<( const record& right) const{
    return a < right.a;
  }
};

int main(void){

  ull n, k;
  cin >> n >> k;
  cin.ignore();
  ull a[n], b[n];
  record s[n];
  ull i;
  for(i=0;i<n;i++){
    cin >> a[i] >> b[i];
    s[i].a = a[i];
    s[i].b = b[i];
    cin.ignore();
  }
  sort(s, s + n);

  for(i=0;i<n;i++){
    //cout << s[i].a << " " << s[i].b << endl;
    if(k <= s[i].b){
      cout << s[i].a << endl;
      return 0;
    } else k-= s[i].b;
  }

  
  return 0;
}
