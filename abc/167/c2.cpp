#include <bits/stdc++.h>

using namespace std;

int n, m;
int x;

int cnt = 0;
int ans = INT_MAX;

vector <int> c;
vector <vector<int> > a;

int mymin(int g, int h){
  return (g < h) ? g : h;
}

int main(){

  
  cin >> n >> m >> x;
  cin.ignore();

  int status = 1 << n;

  int tmp;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    c.push_back(tmp);
    vector <int> tv;
    for(int j = 0; j < m; j++){
      cin >> tmp;
      tv.push_back(tmp);
    }
    a.push_back(tv);
    cin.ignore();
  }
  // 全探索
  int pnt[12] = {0};
  tmp = 0;
  bool pos = false;
  for (int i = 0; i < status; i++){
    for (int j = 0; j < 12; j++){
      pnt[j] = 0;
    }
    tmp = 0;
    for(int j = 0; j < n; j++){
      if((1 << j) & i){
        tmp += c[j];
        for(int k = 0; k < m; k++){
          pnt[k] += a[j][k];
        }
      }
    }

    bool flg = true;
    for(int j = 0; j < m; j++){
      if(pnt[j] < x){
        flg = false;
      }
    }
    if(flg){
      ans = mymin(ans, tmp);
      pos = true;
    }
  }
  if(pos == true){
    cout << ans << endl;
    return 0;
  }

  cout <<"-1" << endl;
  return 0;
}
  
