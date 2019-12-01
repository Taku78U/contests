#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; // 変数名まちがえた
  cin >> n;
  cin.ignore();

  // 戦略 各下一桁に対し、組み合わせを定義

  int m = n % 100;
  if(m == 0){ // 100円のおにぎりだけでいい
    cout << 1 << endl;
    return 0;
  }

  m = n % 101;
  if(m == 0){ // 100円のおにぎりだけでいい
    cout << 1 << endl;
    return 0;
  }

  m = n % 102;
  if(m == 0){ // 100円のおにぎりだけでいい
    cout << 1 << endl;
    return 0;
  }

  m = n % 103;
  if(m == 0){ // 100円のおにぎりだけでいい
    cout << 1 << endl;
    return 0;
  }

  m = n % 104;
  if(m == 0){ // 100円のおにぎりだけでいい
    cout << 1 << endl;
    return 0;
  }

  m = n % 105;
  if(m == 0){ // 100円のおにぎりだけでいい
    cout << 1 << endl;
    return 0;
  }

  if( n < 100){
    cout << 0 << endl;
    return 0;
  }

  // まず100円だけでやってみる

  int d[6] = {0};
  d[0] = n / 100; // 商
  m = n % 100; // 余り

  // 余りをとりあえず105円に置換
  // これが一番少ない数で済む

  d[5] = m / 5;
  m %= 5;

  // d[0] から d[5] を削除

  d[0] -= d[5];
  if(d[0] < 0){ // 負になったら負け
    cout << 0 << endl;
    return 0;
  }

  // この時点で余りなしならOK
  if(m == 0){
    cout << 1 << endl;
    return 0;
  }

  if(d[0] == 0){ // mが余ってるのにdがゼロ
    cout << 0 << endl;
    return 0;
  } else {
    cout << 1 << endl;
    return 0;
  }
  return 0;
}
  
  
