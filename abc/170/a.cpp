#include <bits/stdc++.h>

using namespace std;

int main(){

  int tmp;
  int ans;
  for(int i = 0; i < 5; i++){
    cin >> tmp;
    if(tmp == 0){
      ans = i + 1;
    }

  }
  cin.ignore();
  
  cout << ans << endl;

  return 0;
}
