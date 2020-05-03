#include <bits/stdc++.h>

using namespace std;
int n, k, d;
bool a[100] = {false};

int main(){
  cin >> n >> k;
  cin.ignore();
  int tmp;
  for(int i = 0; i < k; i++){
    cin >> d;
    cin.ignore();
    for(int j = 0; j < d; j++){
      cin >> tmp;
      --tmp;
      a[tmp] = true;
    }
  }
  int cnt = 0;
  for(int i = 0; i < n; i++){
    if(a[i] == false){
      ++cnt;
    }
  }
  cout << cnt << endl;
  
  return 0;
}
