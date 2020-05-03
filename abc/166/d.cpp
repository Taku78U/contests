#include <bits/stdc++.h>

using namespace std;

long long a = 0, b = 0, x = 0;

int main(){
  cin >> x;
  cin.ignore();

  // マイナス方向の探索

  double db_a;
  long long b5;
  for(long long b_ = 0; b_*b_*b_*b_*b_ <= x; b_++){
    b5 = b_*b_*b_*b_*b_;
    db_a = pow((double)(x - b5), 0.2);
    a = round(db_a);
    if(a*a*a*a*a == x - b5){
      if(b_ == 0){
        cout << a << " " << 0 << endl;
        return 0;
      }
      cout << a << " -" << b_ << endl;
      return 0;
    }
  }

  // プラス方向のループ

  b = 1;
  double db_b = 1;
  double b5db;
  while(true){
    b5 = b*b*b*b*b;
    b5db = db_b*db_b*db_b*db_b*db_b;
    //db_a = pow((double)(x+b5db), 0.2);
    db_a = pow((double)(x+b5), 0.2);
    a = round(db_a);
    //if(db_b == 2) cout << a << " " << db_a << endl;
    if(a*a*a*a*a == x+b5){
      cout << a << " " << b << endl;
      return 0;
    }
    ++b;
    db_b += 1;
    //cout << db_b << endl;
  }
  return 0;
}
