#include <bits/stdc++.h>

using namespace std;

int main (void){
  int n;
  cin >> n;
  cin.ignore();

  vector <int> a;
  int tmp;

  int ni = n;
  while (ni--){
    cin >> tmp;
    a.push_back(tmp);
  }
  sort(a.begin(), a.end());
  cout << a.back() - a.front() << endl;
  return 0;
}
