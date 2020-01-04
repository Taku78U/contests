#include <bits/stdc++.h>

using namespace std;

#define NUM 6

int main(){
  vector<int> a;
  int tmp;
  for(int i = 0; i < NUM; i++){
    cin >> tmp;
    a.push_back(tmp);
  }
  sort(a.begin(), a.end());
  cout << a[3] << endl;
  return 0;
}
