#include <bits/stdc++.h>

using namespace std;

int main (void){
  int a, b;
  cin >> a >> b;

  if (abs(a)==abs(b)) cout << "Draw" << endl;
  else if(abs(a) < abs(b)) cout << "Ant" << endl;
  else cout << "Bug" << endl;

  return 0;
}
