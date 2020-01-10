#include <bits/stdc++.h>
//#define DBG

using namespace std;

vector <int> p, q;


int main(){
  int n;
  cin >> n;
  cin.ignore();
  int tmp;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    p.push_back(tmp);
  }
  cin.ignore();
  for(int i = 0; i < n; i++){
    cin >> tmp;
    q.push_back(tmp);
  }
  cin.ignore();

  int array[n];
  for(int i = 0; i < n; i++){
    array[i] = i + 1;
  }

  bool flag_p = true;
  bool flag_q = true;
  int cnt = 1;
  int cnt_p = 0;
  int cnt_q = 0;
  do{
    flag_p = true;
    flag_q = true;
    #ifdef DBG
    for(int i = 0; i < n; i++){
      cout << array[i] << " " << flush;
    }
    cout << endl;
    #endif
    for(int i = 0; i < n; i++){
      flag_p = (array[i] == p[i]);
      if(flag_p == false){
        break;
      }
    }
    if((cnt_p == 0) && (flag_p == true)){
      cnt_p = cnt;
    }
    for(int i = 0; i < n; i++){
      flag_q = (array[i] == q[i]);
      if(flag_q == false){
        break;
      }
    }
    if((cnt_q == 0) && (flag_q == true)){
      cnt_q = cnt;
    }
    ++cnt;
  }while(next_permutation(array, array + n));

  int ans;
  if(cnt_p >= cnt_q){
    ans = cnt_p - cnt_q;
  } else {
    ans = cnt_q - cnt_p;
  }
  cout << ans << endl;
  return 0;
}
      
    
