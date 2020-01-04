#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  cin.ignore();


  if(s == "SUN"){
    cout << 7 << endl;
    return 0;
  } else if(s == "MON"){
    cout << 6 << endl;
    return 0;
  } else if(s == "TUE"){
    cout << 5 << endl;
    return 0;
  } else if(s == "WED"){
    cout << 4 << endl;
    return 0;
  } else if(s == "THU"){
    cout << 3 << endl;
    return 0;
  } else if(s == "FRI"){
    cout << 2 << endl;
    return 0;
  } else if(s == "SAT"){
    cout << 1 << endl;
    return 0;
  }
  return 0;
}
