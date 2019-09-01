#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll sum[200000] = {0};
struct TSK{
  int p;
  int x;

  bool operator<(const TSK &another){
    return (p==another.p) ? x < another.x : p < another.p;
  }
};


int main(){
  int n, q;
  cin >> n >> q;
  cin.ignore();
  for(int i = 0; i < n - 1; i++){
    sum[i] = 0;
  }
  //vector<int> p[n];
  int parent[n] = {0};
  for(int i = 0; i < n; i++){
    parent[i] = -1;
  }
  int a, b;
  for(int i = 0; i < n - 1; i++){
    cin >> a >> b;
    --a;
    --b;
    //p[a].push_back(b);
    parent[b] = a;
    cin.ignore();
  }

  // 更新
  TSK tmp_tsk;
  vector <TSK> t;
  
  for(int i = 0; i < q; i++){
    cin >> tmp_tsk.p >> tmp_tsk.x;
    --tmp_tsk.p;
    t.push_back(tmp_tsk);
    cin.ignore();
  }

  sort(t.begin(), t.end());
  int ptr = 0;
  for(int i = 0; i < n; i++){
    while(t[ptr].p == i){ // それ自身に対する処理
      sum[i] += t[ptr].x;
      ++ptr;
    }
    if(parent[i] != -1){ // 親に対する処理
      sum[i] += sum[parent[i]];
    }
  }

  //for(int i = 0; i < n; i++){
  //  cout << parent[i] << " " << flush;
  //}
  //cout << endl;
  for(int i = 0; i < n; i++){
    cout << sum[i] << " " << flush;
  }
  cout << endl;
  
  return 0;
}

      
