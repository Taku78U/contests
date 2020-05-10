#include <bits/stdc++.h>

using namespace std;

vector <long long> a;

long long tbl[2*100000] = {0}; // 何番目に訪れた？

int main(){
  int n;
  unsigned long long k;
  int tmp;
  cin >> n >> k;
  cin.ignore();

  for(int i = 0; i < n; i++){
    cin >> tmp;
    --tmp;
    a.push_back(tmp);
  }
  cin.ignore();

  // Nまでだったら砂ぽに求める
  if(k <= n){
    int point = 0;
    while(k > 0){
      --k;
      point = a[point];
    }
    cout << point + 1 << endl;
    return 0;
  }

  // どっかでループができている
  for(int i = 0; i < 2*100000; i++){
    tbl[i] = -1;
  }

  tbl[0] = 0; // 0は0番目
  int point = 0;
  long long loop;
  int l_start = 0;
  int cnt = 0;
  while(true){
    tmp = a[point];
    ++cnt;
    if(point == tmp){ // それ以上移動しない
      cout << point + 1 << endl;
      return 0;
    }
    if(tbl[tmp] >= 0){ // tmpと
      loop = cnt - tbl[tmp];
      l_start = tmp;
      tbl[tmp] = cnt;
      break;
    }
    tbl[tmp] = cnt;
    point = tmp;
  }

  /*
  for (int i = 0; i < n; i++){
    cout << tbl[i] << " " << flush;
  }
  cout << endl;
  cout << "loop " << loop << endl;
  cout << "l_start " << l_start << endl;
  */
  // ループをあらためてたどる
  k -= tbl[l_start];
  k %= loop;

  // あとは素直にたどるだけ
  point = l_start;
  while( k > 0){
    k--;
    point = a[point];
  }
  cout << point+1 << endl;
  return 0;
}
