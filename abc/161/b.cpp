#include <bits/stdc++.h>

using namespace std;
int n, m;
vector <int> a;
int main(){
  int tmp;
  cin >> n >> m;
  cin.ignore();
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    sum += tmp;
    a.push_back(tmp);
  }

  int border = sum / (4 * m);
  bool mod = (sum % (4 * m) == 0) ? true : false;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    if((a[i] >= border) && (mod == true)){
      ++cnt;
    } else if((a[i] > border) & (mod == false)){
      ++cnt;
    }
    if(cnt >= m){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
