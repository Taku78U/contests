#include <bits/stdc++.h>

using namespace std;

int main(){
  
  int a, b;
  cin >> a >> b;
  
  cin.ignore();
  
  int plus = a + b;
  int max = plus; 
  int mult = a * b;
  if(max < mult){
    max = mult;
  }
  int minus = a - b;
  if(max < minus){
    max = minus;
  }

  cout << max << endl;
  return 0;
}
  
