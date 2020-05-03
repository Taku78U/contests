#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  cin.ignore();

  std::string filename = "idxprint.txt";
  std::ofstream writing_file;
  writing_file.open(filename,std:: ios::out);

  for(int i = 0; i < s.size(); i++){
    writing_file << i << ": " << s[i] << endl;
  }
  return 0;
}
  
