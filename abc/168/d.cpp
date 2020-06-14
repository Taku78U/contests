#include <bits/stdc++.h>

using namespace std;

queue<int> q;

vector<int> trail[2*100000];
int n, m;

int answers[2*100000];

int main(){
  cin >> n >> m;
  cin.ignore();

  for(int i = 0; i < 200000; i++){
    answers[i] = INT_MAX;
  }

  int tmpa, tmpb;
  for(int i = 0; i < m; i++){
    cin >> tmpa >> tmpb;
    cin.ignore();
    --tmpa;
    --tmpb;
    trail[tmpa].push_back(tmpb);
    trail[tmpb].push_back(tmpa);
  }

  q.push(0);
  int tmp;
  int max = INT_MAX;
  while(!q.empty()){
    if(q.size() == n) break;
    tmp = q.front();
    q.pop();
    if(trail[tmp].empty()) continue;

    int ttmp;
    for(int i = 0; i < trail[tmp].size(); i++){
      ttmp = trail[tmp][i];
      if(answers[ttmp] != INT_MAX) continue; // 訪問済み
      answers[ttmp] = tmp;
      q.push(ttmp);
    }
  }

  cout << "Yes" << endl;

  for(int i = 1; i < n; i++){
    cout << answers[i] + 1 << endl;
  }
  return 0;
}
