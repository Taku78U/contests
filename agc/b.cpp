#include <bits/stdc++.h>

using namespace std;

std::vector<int> find_all(const std::string str, const std::string subStr) {
  std::vector<int> result;

  int subStrSize = subStr.size();
  int pos = str.find(subStr);

  while (pos != std::string::npos) {
    result.push_back(pos);
    pos = str.find(subStr, pos + subStrSize);
  }

  return result;
}

int main(){

  // とりあえずABC->BCA
  //一箇所見つけたら感染させまくる

  string s;
  cin >> s;
  cin.ignore();

  int sum = 0;

  vector<int> findVec;

  while(1){
    findVec = find_all(s, "ABC");
    if(findVec.empty()){
      break;
    }
    // とりあえ末尾まで
    for(const auto &pos:findVec){
      s[pos] = 'B';
      s[pos+1] = 'C';
      s[pos+2] = 'A';
      sum++;
    }
  }

  cout << sum << endl;
  return 0;
}
