#include <bits/stdc++.h>

using namespace std;

int main(){
  vector <int> a, b, c;
  int tmp;
  int n;
  cin >> n;
  cin.ignore();

  for(int i = 0; i < n; i++){
    cin >> tmp;
    a.push_back(tmp - 1);
  }
  cin.ignore();
  for(int i = 0; i < n; i++){
    cin >> tmp;
    b.push_back(tmp);
  }
  cin.ignore();
  for(int i = 0; i < n - 1; i++){
    cin >> tmp;
    c.push_back(tmp);
  }
  cin.ignore();

  int sum = accumulate(b.begin(), b.end(), 0);

  for (int i = 0; i < n - 1; i++){
    if(a[i+1] == a[i] + 1){
      sum += c[a[i]];
    }
  }
  cout << sum << endl;
  return 0;
}
