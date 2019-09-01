#include <bits/stdc++.h>

using namespace std;

std::string replaceAll(std::string &replacedStr, std::string from, std::string to) {
  int pos = replacedStr.find(from);
  int toLen = to.length();

  if (from.empty()) {
    return replacedStr;
  }

  while ((pos = replacedStr.find(from, pos)) != std::string::npos) {
    //cout << pos << endl;
    replacedStr.replace(pos, from.length(), to);
    pos += toLen;
  }
  return replacedStr;
}

int main(){
  string s;
  cin >> s;
  cin.ignore();

  replaceAll(s, "BC", "D");
  //cout << s << endl;

  // Aを数え上げる
  // Dが来たらtempsumへ足す
  // B,Cが来たらtempsumリセット

  long long sum = 0;
  long long tempsum = 0;

  for(int i = 0; i < s.length(); i++){
    if(s[i] == 'A'){
      tempsum++;
    } else if(s[i] == 'D'){
      sum += tempsum;
    } else {
      tempsum = 0;
    }
    //cout << "i = " << i << endl;
    //cout << "tempsum = " << tempsum << endl;
    //cout << "sum = " << sum << endl;
   
  }
  cout << sum << endl;

  
  
}
