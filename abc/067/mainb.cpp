#include <bits/stdc++.h>

using namespace std;

int main (void){
  int n, k;
  cin >> n >> k;
  cin.ignore();
  int l[n] = {0};

  for(int i = 0; i < n; i++){
    cin >> l[i];
  }

  sort(l, l + n);
  int sum = 0;
  for (int i = n - k; i < n; i++){
    sum += l[i];
  }
  cout << sum << endl;
  return 0;
}
