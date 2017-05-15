#include <bits/stdc++.h>

using namespace std;

typedef unsigned short us;

bool notng (us n, us n1, us n2, us n3){
  return (n != n1) && (n != n2) && (n != n3) && (n >= 0);
}

int main (void){
  us n, n1, n2, n3;

  cin >> n;
  cin.ignore();
  cin >> n1;
  cin.ignore();
  cin >> n2;
  cin.ignore();
  cin >> n3;

  // 貪欲法

  us cnt;
  us m;
  us tmp;

  if(!notng(n, n1, n2, n3)){
    cout << "NO" << endl;
    return 0;
  }

  for (cnt = 100; cnt > 0; cnt--){
    for (m = 3; m > 0; m--){
      if(n >= m) tmp = n - m;
      else continue;
      if (tmp == 0) break;
      if (notng(tmp, n1, n2, n3)) break;
      if (m == 1){
        cout << "NO" << endl;
        return 0;
      }
    }
    n = tmp;
    //    cout << "N: " << n << endl;
    if (n == 0) break;
  }

  if (n == 0){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
  
