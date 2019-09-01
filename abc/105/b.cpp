#include <bits/stdc++.h>

using namespace std;

void print_array(int* a, int n){
  for(int i = 0; i < n; i++){
    cout << a[i] << ',' << flush;
  }
  cout << endl;
}

int main (void){
  int n;
  cin >> n;
  cin.ignore();

  int a[n];
  for(int i = 0; i < n; i++){
    a[i] = 0;
  }

  // エラストテネスのふるい風
  for(int i = 1; i <= n; i+=2){
    for(int j = i; j <= n; j+=i){
      a[j-1]++;
    }
  }

  print_array(a, n);

  int num = 0;
  for(int i = 0; i < n; i++){
    if(a[i] == 8) num++;
  }

  cout << num << endl;

  return 0;
}
  
