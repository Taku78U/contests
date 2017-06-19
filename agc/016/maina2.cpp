#include <bits/stdc++.h>

using namespace std;

int main (void){
  string str;
  cin >> str;

  short alp[26] = {0};

  char* s = new char[str.size() + 1];

  strcpy(s, str.c_str());

  for (int i = 0; i < str.size() + 1; i++){
    alp[s[i] - 0x61]++;
  }


  // 全探索

  // 回数テーブル
  short n[26];

  short maxn = 0;
  short tmp = 0;
  short min = 1 << 14;
  short mintmp;
  bool en = false;
  for (char c = 'a'; c <= 'z'; c++){
    en = false;
    // いくつ空いているか？
    maxn = 0;
    tmp = 0;
    for (short i = 0; i < str.size(); i++){
      if(s[i] == c){
        if(maxn < tmp) maxn = tmp;
        tmp = 0;
        en = true;
      }else{
        tmp++;
        if(i == str.size() - 1){
          if(maxn < tmp) maxn = tmp;
        }
      }
    }

    if(en){
      //cout << c << " " << maxn << endl;
      n[c - 0x61] = maxn;
      mintmp = maxn;
      if(min > mintmp) min = mintmp;
    }
  }
  cout << min << endl;
    
  
  return 0;
}
  
