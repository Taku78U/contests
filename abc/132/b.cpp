#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;

  vector<int> p;
  int temp;

  cin >> n;
  cin.ignore();
  for(int i = 0; i < n; i++){
    cin >> temp;
    p.push_back(temp);
  }
  cin.ignore();

  int cnt = 0;
  for (int i = 0; i < n - 2; i++){
    if(((p[i] < p[i + 1]) && (p[i + 1] < p[i + 2]))
       || ((p[i] > p[i + 1]) && (p[i + 1] > p[i + 2]))){
      ++cnt;
    }
  }
  cout << cnt << endl;
  return 0;
}
