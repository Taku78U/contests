#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct ALB{
  ll a; // 日数
  ll b; // 報酬

  // 演算子オーバーロード
 // 演算子オーバーロードで比較関数を定義
  bool operator<(const ALB& another) const {
    return (a == another.a) ? (b > another.b) : (a < another.a);
  }
};

int main(){
  ll n, m;

  cin >> n >> m;

  vector <ALB> alb;
  ALB tmp_alb;
  for(ll i = 0; i < n; i++){
    cin >> tmp_alb.a >> tmp_alb.b;
    --tmp_alb.a;
    cin.ignore();
    if(tmp_alb.a <= m - 1){
      alb.push_back(tmp_alb);
    }
  }

  n = alb.size(); // 実際のサイズに書き換える
  if(n == 0){
    cout << 0 << endl;
    return 0;
  }
  sort(alb.begin(), alb.end()); // この時点でaがm以下しか入っていない

  // 末尾からスタックのごとく引っこ抜く

  tmp_alb = alb[n - 1];

  ll income = 0;

  ALB max_alb;

  //for(ll i = 0; i < n; i++){
  //  cout << alb[i].a << " " << alb[i].b << endl;
  //}

  // A[i] ポインタとも
  int ptrs_begin[m], ptrs_end[m];
  for(int i = 0; i < m; i++){
    ptrs_begin[i] = -1; // NULLの代用
    ptrs_end[i] = -1; // NULLの代用
  }

  // 登録
  ptrs_begin[alb[0].a] = 0;
  ptrs_end[alb[n-1].a] = n-1;
  for(int i = 1; i < n; i++){
    if(alb[i-1].a != alb[i].a){
      ptrs_end[alb[i-1].a] = i - 1;
      ptrs_begin[alb[i].a] = i;
    }
  }

  int ptr = 0;
  int max = 0;
  int maxnum = 0;
  for(int i = 0; i < m; i++){ // i: 残り日数 - 1
    max = 0;
    maxnum = -1;
    for(int j = 0; j <= i; j++){ // maxを調べる
      if(ptrs_begin[j] == -1) continue;
      ptr = ptrs_begin[j];
      if(max < alb[ptr].b){
        max = alb[ptr].b;
        maxnum = j;
      }
    }
    income += max;
    if(maxnum != -1){
      ++ptrs_begin[maxnum];
      if(ptrs_begin[maxnum] > ptrs_end[maxnum]){
        ptrs_begin[maxnum] = -1;
      }
    }
  }

  cout << income << endl;
}
    
  
