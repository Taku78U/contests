#include <bits/stdc++.h>


using namespace std;

int main(){

  int s;

  cin >> s;
  cin.ignore();

  // 月: 1〜12
  // 年: 任意 ただし0以外

  int low = s % 100;
  bool lowmonth = false;
  if ((1 <= low) && (low <= 12)){
    lowmonth = true;
  }

  int high = s / 100;
  bool highmonth = false;
  if ((1 <= high) && (high <= 12)){
    highmonth = true;
  }

  if (lowmonth & highmonth){
    cout << "AMBIGUOUS" << endl;
  } else if(lowmonth){
    cout << "YYMM" << endl;
  } else if(highmonth) {
    cout << "MMYY" << endl;
  } else {
    cout << "NA" << endl;
  }
  return 0;
}
  
