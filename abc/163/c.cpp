#include <bits/stdc++.h>

using namespace std;

int n;
int a[2*100000] = {0};
int main(){
  long long tmp;
  cin >> n;
  cin.ignore();

  for (int i = 0; i < n - 1; i++){
    cin >> tmp;
    ++(a[tmp - 1]);
  }

  for (int i = 0; i < n; i++){
    cout << a[i] << endl;
  }
  return 0;
}
