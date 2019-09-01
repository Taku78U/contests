#include <bits/stdc++.h>

using namespace std;

/*
問題文
N個の空の箱が横一列に並んでいます。 左から 
i番目の箱には整数iが書かれています。

すぬけさんは、それぞれの箱に対してボールを 
1 個入れるか何も入れないかを選ぶことができます。

ここで、以下の条件を満たすようなボールの入れ方を、いいボールの入れ方と定めます。

1以上 N以下の任意の整数 iについて、iの倍数が書かれた箱に入っているボールの個数の和を 
2で割った余りが a_iである。
いいボールの入れ方は存在するでしょうか。存在するならば 
1つ求めてください。*/

int main(){
  int n;
  cin >> n;

  int a[n] = {0};
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  cin.ignore();

  int b[n] = {0};

  // n/2 + 1からnまでは倍数もくそもない
  for(int i = n / 2; i < n; i++){
    b[i] = a[i];
  }

  // あとは全探索
  int tmp; // 次forループのi + 1
  int tmp2; // 次forループにてtmpの倍数
  int tmp_a; // tmp番目までの箱の状況に関わらず箱に入っている玉の数
  for(int i = n / 2 - 1; i >= 0; i--){
    tmp = i + 1;
    tmp_a = 0;
    for(tmp2 = tmp * 2; tmp2 <= n; tmp2 += tmp){
      if(b[tmp2 - 1] == 1){
        ++tmp_a;
      }
      tmp_a %= 2;
    }
    if(tmp_a != a[i]){
      b[i] = 1;
    } else {
      b[i] = 0;
    }
  }
  int m = 0;
  for(int i = 0; i < n; i++){
    m += b[i];
  }
  cout << m << endl;
  if(m == 0) return 0;
  for(int i = 0; i < n; i++){
    if(b[i] == 1){
      cout << i + 1 << " " << flush;
    }
  }
  cout << endl;
  return 0;
}
      
      
    
    

  
