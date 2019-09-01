#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct ALB{
  ll a; // 日数
  ll b; // 報酬

  // 演算子オーバーロード priority_queueの優先度
  bool operator<(const ALB& another) const {
    return (b == another.b) ? (a < another.a) : (b < another.b);
  }
};

// ソート用
bool cmp_alb(const ALB &x, const ALB &y){
  return (x.a == y.a) ? (x.b > y.b) : (x.a < y.a);
}

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
  sort(alb.begin(), alb.end(), cmp_alb); // この時点でaがm以下しか入っていない

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

  // 優先度キューに突っ込みながら候補出しする

  priority_queue<ALB> que;

  // 1日前からループ
  for (int i = 0; i < m; i++){
    if(ptrs_begin[i] != -1){
      for(int j = ptrs_begin[i]; j <= ptrs_end[i]; j++){
        que.push(alb[j]);
        //cout << "alb[j] = " << alb[j].a << " " << alb[j].b << endl;
      }
    }
    if(que.empty() == true) continue;
    tmp_alb = que.top();
    //cout << "que.top() = " << tmp_alb.a << " " << tmp_alb.b << endl;
    income += tmp_alb.b;
    que.pop();
  }
  cout << income << endl;
}
    
  
