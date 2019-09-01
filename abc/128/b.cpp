#include <bits/stdc++.h>

using namespace std;

struct Info{
  string s;
  int p;
  int orig_num;

  bool operator<(const Info &another) const{
    return (s == another.s) ? (p > another.p) : s < another.s;
  }
};

struct InfoB{
  int num;  // 紹介順
  int orig_num;
  bool operator<(const InfoB &another) const{
    return orig_num < another.orig_num;
  }
};
int main(){
  int n;
  vector <Info> ifo;
  cin >> n;
  cin.ignore();
  Info infom;
  for (int i = 0; i < n; i++){
    cin >> infom.s >> infom.p;
    infom.orig_num = i;
    cin.ignore();
    ifo.push_back(infom);
  }
  sort(ifo.begin(), ifo.end());

  for (int i = 0; i < n; i++){
    //cout << ifo[i].s << " " << ifo[i].p << endl;
    cout << ifo[i].orig_num + 1 << endl;
  }

  return 0;
  
}
