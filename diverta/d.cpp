#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){

  int n;
  cin >> n;
  cin.ignore();
  int ga, sa, ba;
  int gb, sb, bb;

  cin >> ga >> sa >> ba;
  cin.ignore();
  cin >> gb >> sb >> bb;
  cin.ignore();

  // アビトラ

  double dg, ds, db;
  dg = ((double)gb) / ga;
  ds = ((double)sb) / sa;
  db = ((double)bb) / ba;

  // どっちで金属をどんぐりに両替？ True: B False: A
  bool g, s, b;
  g = (dg > 1);
  s = (ds > 1);
  b = (db > 1);

  if(g && s && b){ // 増加率の高い方からA→Bアビトラすれば終わり
    if(g > s && s > b){
      // gから先にいく
      
    


  // 最大 - 最小 が最後に起きる
}
