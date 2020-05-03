#include <bits/stdc++.h>

using namespace std;

int n, m;

int main(){
  cin >> n >> m;
  cin.ignore();

  //for(int i = 1; i <= m; i++){
  //  cout << i << " " << n - i << endl;
  //}

  int a, b;
  if(n % 2 == 0){
    a = n / 2;
    b = n / 2 + 1;
  } else {
    a = n / 2;
    b = n / 2 + 1;
  }

  for (int i = 0; i < m; i++){
    cout << a - i << " " << b + i << endl;
  }
  
  return 0;
}
