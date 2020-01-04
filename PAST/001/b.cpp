#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<int> a;
  int n;
  int tmp;
  cin >> n;
  cin.ignore();

  for(int i = 0; i < n; i++){
    cin >> tmp;
    cin.ignore();
    a.push_back(tmp);
  }

  int dif;
  for(int i = 1; i < n; i++){
    if(a[i] == a[i-1]){
      cout << "stay" << endl;
    } else if(a[i] > a[i-1]){
      dif = a[i] - a[i-1];
      cout << "up " << dif << endl;
    } else {
      dif = a[i-1] - a[i];
      cout << "down " << dif << endl;
    }
  }
  return 0;
}
