#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int main(){
  ull n;
  cin >> n;
  cin.ignore();

  vector <ull> a;
  ull tmp;
  ull s = 0;

  ull min, max;
  min = 1000000000 + 1;
  max = 0;
  for (ull i = 0; i < n; i++){
    cin >> tmp;
    s = s ^ tmp;
    if(min > tmp){
      min = tmp;
    }
    if(max < tmp){
      max = tmp;
    }
    a.push_back(tmp);
  }

  //cout << "max = " << max << endl;
  //cout << "min = " << min << endl;

  // 4種類以上でNG
  ull mid;
  bool midfind = false;
  for (ull i = 0; i < n; i++){
    if((a[i] != min) && (a[i] != max)){
      mid = a[i];
      midfind = true;
      break;
    }
  }

  //cout << "mid = " << mid << endl;

  ull mincnt = 0;
  ull midcnt = 0;
  ull maxcnt = 0;
  if(min == max){
    cout << "No" << endl;
    return 0;
  }
  if(midfind == false){
    if(min != 0){
      //cout << 1 << endl;
      cout << "No" << endl;
      return 0;
    }
    for(ull i = 0; i < n; i++){
      if(min == a[i]){
        ++mincnt;
      } else if(max == a[i]){
        ++maxcnt;
      }
    }
    if(maxcnt == mincnt * 2){
      cout << "Yes" << endl;
      return 0;
    }
  }

  if(midfind == true){
    for(ull i = 0; i < n; i++){
      if((a[i] != min) && (a[i] != mid) && (a[i] != max)){
        //cout << mid << endl;
        cout << "No" << endl;
        return 0;
      } else if(a[i] == min){
        ++mincnt;
      } else if(a[i] == mid){
        ++midcnt;
      } else if(a[i] == max){
        ++maxcnt;
      }
    }
    if((mincnt == midcnt) && (midcnt == maxcnt)){
      cout << "Yes" << endl;
      return 0;
    } else {
      //cout << 444 << endl;
      cout << "No" << endl;
      return 0;
    }
  }
  return 0;

  if(n % 3 == 0){
    if(s == 0){

      
      cout << "Yes" << endl;
      return 0;
    } else {
      cout << "No" << endl;
      return 0;
    }
  } else {
    cout << "No" << endl;
    return 0;
  }

  return 0;
}
