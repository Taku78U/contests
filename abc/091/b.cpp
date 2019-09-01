#include <bits/stdc++.h>

using namespace std;

int main(void){
  int n, m;
  cin >> n;
  cin.ignore();
  vector<string> s, t;
  string tmps;
  for(int i = 0; i < n; i++){
    cin >> tmps;
    s.push_back(tmps);
    cin.ignore();
  }
  cin >> m;
  cin.ignore();
  for(int i = 0; i < m; i++){
    cin >> tmps;
    cin.ignore();
    t.push_back(tmps);
  }

  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  // 上から探す。対象が小さくなったら止める
  auto itrs = s.begin();
  auto itrt = t.begin();
  int a = 0;
  int tmp = 0;
  while(itrs != s.end()){
    //itrt = t.begin();
    tmps = *itrs;
    tmp = 0;
    while(itrs != s.end() && tmps==*itrs){
      tmp++;
      //cout << tmps << "!!!" << endl;
      itrs++;
    }
    while(itrt != t.end() && tmps > *itrt){
      itrt++;
      //cout << "0000" << endl;
    }
    //cout << "1111" << endl;
    while(itrt != t.end() && tmps == *itrt){
      tmp -= 1;
      //cout << "2222" << endl;
    //cout << *itrt << endl;
      itrt++;
    }
    if(a < tmp){
      //cout << "TMP:" << tmps << tmp << endl;
      a = tmp;
    }
    if(itrs == s.end()) break;
  }

  if(a < 0) cout << 0 << endl;
  else cout << a << endl;
  

  return 0;
}
