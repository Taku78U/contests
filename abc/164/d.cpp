#include <bits/stdc++.h>

using namespace std;

//int tbl [10000+1] = {0}; // 2019の倍数
string tbl_str[10000+1] = {""}; // 上記のテーブル

/*
strict Info{
  int left;
  int right;
  Info(int in_l, int in_r){
    left = in_l;
    right = in_r;
  }
};
*/
//zvector<Info> vv [10000]; // 出現箇所をまとめる 

int main(){
  string str;
  cin >> str;
  cin.ignore();

  int tmp;
  string tmp_str;
  for(int i = 1; i < 10000; i++){
    tmp = 2019 * i;
    tmp_str = to_string(tmp);
    if(tmp_str.find("0") == string::npos){
      tbl_str[i] = "";
    } else {
      tbl_str[i] = tmp_str;
    }
  }

  // 最初はどこ？
  int start_pos = 0;
  int tmp_pos = 0;
  int cnt = 0;
  int renzoku = 0;
  while((tmp_pos != string::npos) && (start_pos < str.size())){
    for(int i = 1; i < 10000; i++){
      if(tbl_str[i] == "") continue;
      tmp_pos = (str.substr(start_pos)).find(tbl_str[i]);
      if(tmp_pos != string::npos){
        start_pos = tmp_pos + 1;
        ++cnt;
        break;
      }
    }
  }
    cout << cnt << endl;
  return 0;
}
