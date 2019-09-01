#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  vector <int> w;
  cin >> n;
  cin.ignore();
  int tmp;

  for (int i = 0; i < n; i++){
    cin >> tmp;
    w.push_back(tmp);
  }
  cin.ignore();

  // 総和
  int sum = accumulate(w.begin(), w.end(), 0);

  int s1 = 0;
  int s2;

  int ab = sum;
  int minab;

  for (int i = 0; i < n - 1; i++){
    s1 += w[i];
    s2 = sum - s1;
    ab = abs(s1-s2);
    if(i == 0){
      minab = ab;
    } else {
      if(ab < minab){
        minab = ab;
      } else {
        cout << minab << endl;
        return 0;
      }
    }
  }

  cout << ab << endl;


  return 0;
}
