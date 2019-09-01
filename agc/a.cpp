#include <bits/stdc++.h>

using namespace std;

int main(void){
  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d;
  cin.ignore();
  cin >> s;
  cin.ignore();

  // a<b<dより、ふぬけ君から先に行けばいい

  // 0-origin
  a--;
  b--;
  c--;
  d--;

  // ふぬけ
  int len = s.length();

  int su = a;
  int fu = b;

  //for(int i =b; i < len; i++){

  if (d < c){
  // d < c の場合、まずすぬけがふぬけを追い越す必要がある
  // 追い抜ける場所は、前後に岩がないところ=p
  // とりあえずふぬけをそっちに移動
  // すぬけが先にゴールにいく
  // ふぬけが後

    // pを見つける
    int p = b;

    //0方向にすぬけ、前が空白の場合はそのまま

    if((p>0) && (s[p+1] == '.') && (a == p - 1)){
      p = b;
    } else {
      while(p <= d){

        // 場所が条件を満たすか判定
        if((s[p-1] == '.') && (s[p+1] == '.')){
          break;
        }

        // pの条件判定
        // pが末尾dの場合、すでに無理
        if(p>=d){
          cout << "No" << endl;
          return 0;
        } else if((p == d - 1) && (s[d] == '#')){ //n pが後ろから2つめ、前が岩
          cout << "No" << endl;
          return 0;
        } else if((s[p] == '#') && (s[p + 1] == '#')){ // 2連続で岩ならその時点でNG
          cout << "No" << endl;
          return 0;
        }

        // 前が岩なら2つ進める
        // 文の条件から、ぜったいにdにたどり着く
        if(s[p + 1] == '#'){
          p+=2;
        } else {
          p++;
        }
      }
    }
    fu = p;

    // すぬけはふぬけの開始位置-1までいければ追い抜ける
    // その途中に岩が2連続でなければOK
    for(int i = a + 1; i < b - 1; i++){
      if((s[i] == '#') && (s[i+1] == '#')){
        cout << "No" << endl;
        return 0;
      }
    }

    // すぬけはふぬけを追い越した
    su = fu + 1;

    // すぬけから先にゴール

    for(int i = su + 1; i < c - 1; i++){
      if((s[i] == '#') && (s[i+1] == '#')){
        cout << "No" << endl;
        return 0;
      }
    }

    for(int i = fu + 1; i < d - 1; i++){
      if((s[i] == '#') && (s[i+1] == '#')){
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
    return 0;
  } else { // c < d
    // ふぬけから先に動かす
    for(int i = b + 1; i < d - 1; i++){
      if((s[i] == '#') && (s[i+1] == '#')){
        cout << "No" << endl;
        return 0;
      }
    }

    for(int i = a + 1; i < c - 1; i++){
      if((s[i] == '#') && (s[i+1] == '#')){
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
    return 0;
  }

  cout << "Illegal" << endl;
  return 0;
  
}

    

        
