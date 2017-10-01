#include <bits/stdc++.h>

using namespace std;

void poss(void){
  cout << "Possible" << endl;
  return;
}

void imp(void){
  cout << "Impossible" << endl;
  return;
}

int main(void){
  int a, b;
  cin >> a >> b;

  if(a % 3 == 0){
    poss();
  } else if(b % 3 == 0){
    poss();
  }else if((a + b) % 3 == 0){
    poss();
  }else imp();
  return 0;
}
