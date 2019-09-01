#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int main(){
  ull n;
  cin >> n;
  cin.ignore();

  vector <ull> a;
  ull tmp;
  ull s = 0;

  for (ull i = 0; i < n; i++){
    cin >> tmp;
    s = s ^ tmp;
    a.push_back(tmp);
  }

  if(n % 3 == 0){
    if(s == 0){
      cout << "Yes" << endl;
      return 0;
    } else {
      cout << "No" << endl;
      return 0;
    }
  } else {
    ull cnt = 0;
    for (uint i = 0; i < n; i++){
      if(s == a[i]){
        cnt++;
        if(cnt == 2){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
    cout << "No" << endl;
    return 0;
  }

  return 0;
}
