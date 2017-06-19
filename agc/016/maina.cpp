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

  short maxa, max = 0;
  for (short i = 0; i < 26; i++){
    if(max < alp[i]){
      maxa = i;
      max = alp[i];
    }
  }

  char maxc = maxa + 0x61;

  // いくつ空いているか？

  short maxn = 0;
  short tmp = 0;
  for (short i = 0; i < str.size() + 1; i++){
    if(s[i] == maxc){
      if(maxn < tmp) maxn = tmp;
      tmp = 0;
    }else{
      tmp++;
    }
  }

  cout << maxn << endl;
    
  
  return 0;
}
  
