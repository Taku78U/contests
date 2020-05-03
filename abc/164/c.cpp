#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();

  map <string, int> mp;

  string str;
  for(int i = 0; i < n; i++){
    cin >> str;
    cin.ignore();
    if(mp.find(str) == mp.end()){
      mp.insert(make_pair(str, 1));
    } 
  }

  cout << mp.size() << endl;
  return 0;
}
  
