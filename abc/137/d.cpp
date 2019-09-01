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
    cin.ignore();
    if(tmp_alb.a <= m){
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
  ll tmp_m = m; // のこり何日間？一つバイトするごとに減る

  ll income = 0;

  ll max = 0;

  ALB max_alb;

  ll ptr = 0;

  bool even = false;

  ll j = 0;

  for(ll i = 0; i < n; i++){
    cout << alb[i].a << " " << alb[i].b << endl;
  }
  
  for(ll i = 1; i <= m; i++){ // i: 残り日数
    even = false;
    max = 0;
    cout << "i = " << i << endl;
    // 残りi日の中で最大の報酬を得る
    cout << "prev ptr = " << ptr << endl;
    // 先頭ですでに超えている場合はポインタは操作しない
    if(alb[i].a > i) continue;
    for (j = ptr++; j < n; j++){
      if(i < alb[j].a){
        cout << "caseA" << endl;
        //ptr = j;
        break;
      }
      if(max < alb[j].b){
        cout << "caseB" << endl;
        max = alb[j].b;
        max_alb = alb[j];
        even = true;
        cout << alb[i].a << " " << alb[j].b << " " << endl;
      }
    }
    if(even == true){
      income += max;
    }
    cout << "ptr = " << ptr << endl;
    
  }

  cout << income << endl;
}
    
  
