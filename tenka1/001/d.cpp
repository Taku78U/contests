#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

typedef struct tpl{
  ull a;
  ull b;

  bool operator<( const tpl& right ) const {
    return a == right.a ? b < right.b : a < right.a;
  }
};

template <typename T>
inline std::string to_bin_str(T n) {
  std::string str;
  if(n == 0) return "0";
  else while (n > 0) {
    str.push_back('0' + (n & 1));
    n >>= 1;
  }
  reverse(str.begin(), str.end());
  return str;
}

int main(void) {
  ull n, k;
  cin >> n >> k;
  cin.ignore();
  tpl c[n];
  //ull a[n], b[n];
  int j = 0; // c[i].b <= k
  for (int i = 0; i < n; i++){
    //cin >> a[i] >> b[i];
    cin >> c[i].a >> c[i].b;
    cin.ignore();
  }

  // 1-finder

  string strk = to_bin_str(k);
  //cout << "strk = " << strk << endl;
  unsigned int klen = strk.length(); // kの長さ
  char cstrk[klen];
  strcpy(cstrk, strk.c_str());
  vector<ull> masks;
  ull mask;
  masks.push_back(k);
  unsigned int keta;
  //cout << "klen = " << klen << endl;
  //ncout << "cstrk = " << cstrk << endl;
  for (int i = 0; i < klen; i++){
    if(cstrk[i] == '1'){
      keta = klen - i - 1;
      mask = k - (1 << keta);
      mask |= (1 << keta) - 1;
      //cout << "mask = " << mask << endl;
      masks.push_back(mask);
    }
  }

  vector <ull> anss;
  ull ans = 0;
  ull maxans = 0;
  for (auto itr = masks.begin(); itr != masks.end(); itr++){
    ans = 0;
    for (int m = 0; m < n; m++){
      if(*itr == (*itr | c[m].a)){
        ans+=c[m].b;
        //cout << "ans = " << ans << endl;
        //cout << "cmb = " << c[m].b << endl;
      }
    }
    if(maxans <= ans) maxans = ans;
    anss.push_back(ans);
  }
  cout << maxans << endl;

  return 0;
}
