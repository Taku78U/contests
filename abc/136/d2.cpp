#include <bits/stdc++.h>


using namespace std;

// RL 前のR数と後ろのL数
struct RLP{
  int p; // R最後尾の配列インデックス
  int r; // pを含めた、pまでの連続したR数
  int l; // pを含まない、p+1から次の境目までのL数
  int np; // pに集まる人間の数
  int npp; // p+1に集まる人間の数
};
  

void printarray(int* a, int n){
  for(int i = 0; i < n; i++){
    cout << a[i] << " " << flush;
  }
  cout << endl;
}

int main(){
  string s;
  cin >> s;
  cin.ignore();

  int n = s.length();

  vector <RLP> rlp;
  RLP tmp_rlp;
  tmp_rlp.r = 0;
  tmp_rlp.l = 0;
  tmp_rlp.p = 0;
  tmp_rlp.np = 0;
  tmp_rlp.npp = 0;
  bool prev_r = true;
  for (int i = 0; i < n; i++){
    if(s[i] == 'R'){
      if(prev_r == false){
        rlp.push_back(tmp_rlp);
        tmp_rlp.l = 0;
        tmp_rlp.r = 0;
      }
      ++tmp_rlp.r;
      prev_r = true;
    }else if(s[i] == 'L'){
      if(prev_r == true){
        tmp_rlp.p = i - 1; // i==0ではありえない
      }
      ++tmp_rlp.l;
      prev_r = false;
    }
  }

  // 最後のtmp_rlpを入れる(最後はLだからfor中の条件に引っかからない)
  rlp.push_back(tmp_rlp);

  // 10の100乗は偶数
  // しかも収束するには十分
  // ということは
  // pには、pから偶数の距離を持つ人が集まる。
  // p+1には、pから奇数の距離を持つ人が集まる。
  for (int i =0; i < rlp.size(); i++){
    //cout << "RLP [" << i << "] : p = " << rlp[i].p << ", r = " << rlp[i].r << ", l = " << rlp[i].l << endl;
    rlp[i].np = rlp[i].r / 2 + rlp[i].l / 2;
    if(rlp[i].r % 2 == 0){
      rlp[i].np = rlp[i].r / 2;
      rlp[i].npp = rlp[i].r / 2;
    } else {
      rlp[i].np = rlp[i].r / 2 + 1;
      rlp[i].npp = rlp[i].r / 2;
    }
    if(rlp[i].l % 2 == 0){
      rlp[i].np += rlp[i].l / 2;
      rlp[i].npp += rlp[i].l / 2;
    } else {
      rlp[i].np += rlp[i].l / 2 ;
      rlp[i].npp += rlp[i].l / 2 + 1;
    }
  }

  // 表示
  for(int i = 0, ptr = 0; i < n; i++){
    if(ptr >= rlp.size()) {
      cout << 0 << " " << flush;
      continue;
    }
    if(rlp[ptr].p == i){
      cout << rlp[ptr].np << " " << rlp[ptr].npp << " " << flush;
      ++i;
      ++ptr;
    } else {
      cout << 0 << " " << flush;
    }
  }

  
  return 0;
}
  
