#include <bits/stdc++.h>

using namespace std;

//#define DBG

int main(){
  string s;
  cin >> s;
  cin.ignore();

  vector <string> svec;
  int ptr = 0;

  // ステートマシン
  // 0:
  int state = 0;

  string tmp_s;
  
  for(int i = 1; i < s.size(); i++){
    if(('a' <= s[i]) && (s[i] <= 'z')){
      continue;
      #ifdef DBG
      cout << "CNTN" << endl;
      #endif
    }

    // 小文字以外は大文字なので切り出す
    tmp_s = s.substr(ptr, i - ptr + 1);
#ifdef DBG
    cout << "TMP = " << tmp_s << endl;
#endif
    // sortを機能させるた最初・最後の大文字を小文字にする
    tmp_s[0] += 0x20;
    tmp_s[tmp_s.size() - 1] += 0x20; 
    svec.push_back(tmp_s);
    ptr = ++i;
  }
  sort(svec.begin(), svec.end());
#ifdef DBG
  for (int i = 0; i < svec.size(); i++){
    cout << svec[i] << endl;
  }
#endif

  //回答出力
  for(int i = 0; i < svec.size(); i++){
    tmp_s = svec[i];
    tmp_s[0] -= 0x20;
    tmp_s[tmp_s.size() - 1] -= 0x20;
    cout << tmp_s << flush;
  }
  cout << endl;
  return 0;
}
  
