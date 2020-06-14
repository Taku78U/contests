#include <bits/stdc++.h>
#include "../../mylibs.hpp"

using namespace std;

int n;

// AiAj=-BiBj
// Ai/Bi=-Bj/Aj

// key: Ai/Bi
unordered_map<double, vector<int>> mp;

vector<int> a, b;
vector<double> x;

const long long MOD = 1000000007;

int main(){
  cin >> n;

  cin.ignore();

  int tmpa, tmpb;
  double tmpx;
  for(int i = 0; i < n; i++){
    cin >> tmpa >> tmpb;
    cin.ignore();
    tmpx = tmpb / (double) tmpa;
    x.push_back(tmpx);

    if(mp.find(tmpx) == mp.end()){
      vector<int> tmpv;
      tmpv.push_back(i);
      mp[tmpx] = tmpv;
    } else {
      mp[tmpx].push_back(i);
    }
  }

  // 負でないものに対して要素抽出

  long long ans = 1;

  modfactgen(MOD);

  long long size_total = 0; // 仲悪いグループ
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    cout <<"aa" << endl;
    double tmp_key = itr -> first;
    cout <<tmp_key << endl;
    if(tmp_key <= 0) continue;
    int size = (itr -> second).size();
    if(mp.find(-1/tmp_key) == mp.end()) continue;
    int size_r = mp[-1/tmp_key].size();
    cout << "l = " << size << " r = " << size_r << endl;
    long long lef = modfastpow(2, size, MOD);
    long long rig = modfastpow(2, size_r, MOD);
    cout << "lp = " << lef << " rp = " << rig << endl;
    ans = modmult(ans, modpls(modfastpow(2, size, MOD), modfastpow(2, size_r, MOD), MOD), MOD) - 1;
    size_total += size + size_r;
    cout <<"aa" << endl;
  }

  cout << "size_total = " << size_total << endl;

  ans = modmult(ans, modfastpow(2, n - size_total, MOD) , MOD);
  cout << ans - 1 << endl;
  return 0;
}
  
