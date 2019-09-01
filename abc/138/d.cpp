#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll sum[200000] = {0};
vector<int> p[200000];

// 更新処理
// p: ノード x: プラス数 n:サイズ
void upd(int node, int x){
  sum[node] += (ll) x;
  vector <int> vec = p[node];
  //cout << "A" << flush;
  //cout << node << flush;
  //cout << " " << flush;
  //cout << x << endl;
  if(vec.size() == 0) return;
  for(int i = 0; i < vec.size(); i++){
    upd(vec[i], x);
  }
}
int main(){
  int n, q;
  cin >> n >> q;
  cin.ignore();
  for(int i = 0; i < n - 1; i++){
    sum[i] = 0;
  }
  //vector<int> p[n];
  int a, b;
  for(int i = 0; i < n - 1; i++){
    cin >> a >> b;
    --a;
    --b;
    p[a].push_back(b);
    cin.ignore();
  }

  // 更新
  int node, x;
  for(int i = 0; i < q; i++){
    cin >> node >> x;
    --node;
    upd(node, x);
    cin.ignore();
  }

  //cout << "A" << endl;

  for(int i = 0; i < n; i++){
    cout << sum[i] << " " << flush;
  }
  cout << endl;
  
  return 0;
}

      
