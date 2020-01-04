#include <bits/stdc++.h>
//#define DBG
using namespace std;
using ll = long long;

// 最適手
char pref_jan(char c){
  if(c == 'r'){
    return 'p';
  } else if(c == 's'){
    return 'r';
  } else if(c == 'p'){
    return 's';
  }
  return 'a';
}

int r, s, p;
int add_win(char c){
  if(c == 'r'){
    return p;
  } else if(c == 's'){
    return r;
  } else if(c == 'p'){
    return s;
  }
  return 0;
}
char taka[100001] = {'\0'};

int main(){
  string t;
  int n, k;
  cin >> n >> k;
  cin.ignore();
  cin >> r >> s >> p;
  cin.ignore();
  cin >> t;
  cin.ignore();

  int r_n = 0, s_n = 0, p_n = 0;
  for(int i = 0; i < n; i++){
    if(t[i] == 'r'){
      ++r_n;
    } else if(t[i] == 's') {
      ++s_n;
    } else {
      ++p_n;
    }
  }


  cout << score << endl;
  return 0;
}
