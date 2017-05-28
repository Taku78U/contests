#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main (void){
  ll h, w;
  cin >> h >> w;
  cin.ignore();

  if((h % 3 == 0) || (w % 3 == 0)){
    cout << "0" << endl;
    return 0;
  }

  // 横をすべて１つめが取る
  // 3つはなるべく長さ均等になる

  ll p1, p2, p3, p4, p5, p6;

  if(h % 3 != 0) p1 = w;
  if(w % 3 != 0) p2 = h;

  // 横に均等になろうとする場合

  ll l;
  ll al;
  ll am;
  ll cs, stmp;
  ll smin = 0, smax = 0;

  cs = 1LL << 50;
  ll css = 0, cst = 0, csu = 0;
  for (int i = 1; i <= h - 1; i++){
    cst = i * w;
    // まず横切り
    l = h - i;
    al = l / 2;
    if(al != 0){
      am = l % 2;
      css = (al + am) * w;
      smax = (css > cst) ? css : cst; 
      css = al * w;
      smin = (css < cst) ? css : cst;
      stmp = smax - smin;
      if(cs > stmp) cs = stmp;
      //cout << " aa " << cs << endl;
    }
    //そして縦切り
    l = w;
    al = l / 2;
    if(al == 0) continue;
    am = l % 2;
    css = (al + am) * (h - i);
    smax = (css > cst) ? css : cst; 
    css = al * (h - i);
    smin = (css < cst) ? css : cst;
    stmp = smax - smin;
    if(cs > stmp) cs = stmp;
    //cout << " aa " << cs << endl;
  }

  for (int i = 1; i <= w - 1; i++){
    cst = i * h;
    // まず縦切り
    l = w - i;
    al = l / 2;
    if(al != 0){
      am = l % 2;
      css = (al + am) * h;
      smax = (css > cst) ? css : cst; 
      css = al * h;
      smin = (css < cst) ? css : cst;
      stmp = smax - smin;
      if(cs > stmp) cs = stmp;
    }
    //そして横切り
    l = h;
    al = l / 2;
    if(al == 0) continue;
    am = l % 2;
    css = (al + am) * (w - i);
    smax = (css > cst) ? css : cst; 
    css = al * (w - i);
    smin = (css < cst) ? css : cst;
    stmp = smax - smin;
    if(cs > stmp) cs = stmp;
  }

  cout << cs << endl;
  return 0;
}
