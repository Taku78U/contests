#include <bits/stdc++.h>
int n,m;
using namespace std;
vector<int> h;

struct MyTrail{
  int a;
  int b;
  MyTrail(int in_a, int in_b){
    a = in_a;
    b = in_b;
  }
  bool operator<(const MyTrail& another) const{
    return (a == another.a) ? b < another.b : a < another.a;

  }
};
int cnt = 0;
int tcnt = 0;

bool flg[1000000] = {false};
vector<MyTrail> v;

int main(){
  cin >> n >> m;
  cin.ignore();
  int tmp;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    h.push_back(tmp);
  }
  int tmpa, tmpb;
  for(int i = 0; i < m; i++){
    cin >> tmpa >> tmpb;
    if(tmpa > tmpb){
      tmp = tmpb;
      tmpb = tmpa;
      tmpa = tmp;
    }
    v.push_back(MyTrail(--tmpa, --tmpb));
  }
  sort(v.begin(), v.end());

  for(int i = 0; i < v.size(); i++){
    if(h[v[i].a] < h[v[i].b]) flg[v[i].a] = true;
    else if(h[v[i].b] < h[v[i].a]) flg[v[i].b] = true;
    else {
      flg[v[i].a] = true;
      flg[v[i].b] = true;
    }
  }
  
  for(int i = 0; i < h.size(); i++){
    if(flg[i] == false){
      ++cnt;
    }
  }
  cout << cnt << endl;
  return 0;
  
}
