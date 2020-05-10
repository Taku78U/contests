#include <bits/stdc++.h>

using namespace std;

int n, m;
int x;

int cnt = 0;
int ans = INT_MAX;

vector <int> c;
vector <vector<int> > a;

int mymin(int k, int l){
  return (k < l) ? k : l;
}

// pnt: ポイント
// num:番号
bool pos = false;
void dfs(vector<int> pnt, int num, int sum){
  cout << "num " << num << " sum " << sum << endl;
  for(int i = 0; i < m; i++){
    cout << pnt[i] << " " << flush;
  }
  cout << endl;
  cout << endl;

  if(num >= n){
    // チェック
    bool flg = true;
    for(int i = 0; i < m; i++){
      if(pnt[i] < x) flg = false;
      break;
    }
    if(flg == true){
      pos = true;
      ans = mymin(ans, sum);
    }
    return;
  }

  // numを取らない場合
  dfs(pnt, num + 1, sum);

  // numを取った場合
  for(int i = 0; i < m; i++){
    pnt[i] += a[num][i];
  }
  sum += c[num];
  dfs(pnt, num + 1, sum);
}

int main(){
  cin >> n >> m >> x;
  cin.ignore();

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
  vector<int> pnt;
  for(int i = 0; i < m; i++){
    pnt.push_back(0);
  }

  dfs(pnt, 0, 0);
  if(pos == true){
    cout << ans << endl;
    return 0;
  }

  cout <<"-1" << endl;
  return 0;
}
  
