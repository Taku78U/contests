#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> graph[100000];

pair <int, bool> search(int start, int end, int par, pair<int, bool> t, vector<int> cl){
  if(t.second) return t;
  int cnta = t.first;
  pair <int, bool> a;
  for(auto it = graph[start].begin(); it != graph[start].end(); it++){
    if(*it == par) continue;
    else if(*it == end){
      return make_pair(cnta + 1, true);
    } else {
      a = search(*it, end, start, make_pair(cnta + 1, false));
      if(a.second) return a;
    }
  }
  return a;
}

int main(void){
  int n;
  cin >> n;
  cin.ignore();
  int a[n] = {0};
  int b[n] = {0};
  for(int i = 0; i < n - 1; i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    cin.ignore();
  }

  // 隣接リスト
  for(int i = 0; i < n - 1; i++){
    graph[a[i]].push_back(b[i]);
    graph[b[i]].push_back(a[i]);
  }
  vector<int> cl;
  cl.push_back(0);
  pair<int, bool> t = make_pair(0, false);
  t = search(0, n - 1, 0, t, cl);
  if(t.second == false){
    cerr << t.first << endl;
    cerr << "ERROR" << endl;
    exit(1);
  }
  cout << "Dist = " << t.first << endl;
  return 0;
}
