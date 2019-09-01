#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, d;
  cin >> n >> d;


  int asize = n * d;
  // i番目j次元の数値 x[D*i+j]

  vector <int> x;
  int tmp;

  for (int i = 0; i < n; ++i){
    for (int j = 0; j < d; ++j){
      cin >> tmp;
      x.push_back(tmp);
    }
    cin.ignore();
  }

  int cnt = 0;
  double sqtmp;
  int sum = 0;
  int cel;
  int flr;

  for (int i = 0; i < n - 1; i++){
    // 0次元からD-1次元まで和とする
    for(int k = i + 1; k < n; k++){
      sum = 0;
      for(int j = 0; j < d; j++){
        sum+= (x[d*i+j] - x[d*k + j]) * (x[d*i+j] - x[d*k + j]);
      }
      sqtmp = sqrt((double)sum);
      cel = ceil(sqtmp);
      flr = floor(sqtmp);
      //cout << "sqrt = " << sqtmp << endl;
      //cout << "ceil = " << cel << endl;
      //cout << "floor = " << flr << endl;
      if((cel * cel == sum) || (flr * flr == sum)){
        ++cnt;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
    
