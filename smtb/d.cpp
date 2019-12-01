#include <bits/stdc++.h>

//#define DBG
//#define DBG2

using namespace std;

using ll = long long;

static bool t [10][10][10];

int main(){
  int n;
  cin >> n;
  cin.ignore();

  string s;
  cin >> s;
  cin.ignore();

  vector <int> v[10];
  int i_tmp;
  for (int i = 0; i < n; i++){
    i_tmp = (int) (s[i] - '0');
    v[i_tmp].push_back(i);
  }

  int cnt = 0; // こたえ
  int first = 0, second = 0, third = 0;

  vector <int>::iterator itr, itr2, itr3;

#ifdef DBG2
  for (int i = 0; i <= 9; i++){ //最初
    for(itr = v[i].begin(); itr != v[i].end(); itr++){
      cout << *itr << " " << flush;
    }
    cout << endl;
  }
#endif

  
  for (int i = 0; i <= 9; i++){ //最初
    if(v[i].empty() == true){
      continue;
    }

    itr = v[i].begin();
    first = *itr;
#ifdef DBG
    cout << "i = " << i << endl;
    cout << "first = " << first << endl;
#endif

    for(int j = 0; j <= 9; j++){
      if(v[j].empty() == true){
        continue;
      }
      if(i == j){
        if(v[j].size() <= 1){
          continue;
        }
      }

      itr2 = v[j].begin();
      if(i == j){
        ++itr2;
      }

      for(; itr2 != v[j].end(); itr2++){
        second = *itr2;
#ifdef DBG
        cout << "j = " << j << endl;
        cout << "second = " << second << endl;
#endif
        if(second > first){
          // 3つめの検索
          for(int k = 0; k <= 9; k++){
            if(v[k].empty() == true){
#ifdef DBG
              cout << "K EMP" << endl;
#endif
              
              continue;
            }
            if((i == k) || (j == k)){
              if(v[k].size() <= 1){
#ifdef DBG
                cout << "K SIZE less 1" << endl;
#endif
                continue;
              }
            }
            if((i == k) && (j == k)){
              if(v[k].size() <= 2){
#ifdef DBG
                cout << "K SIZE less 2" << endl;
#endif
                continue;
              }
            }
            itr3 = v[k].begin();
            if((i == k) || (j == k)){
              ++itr3;
              if((i == k) && (j == k)){
                ++itr3;
              }
            }

            for(; itr3 != v[k].end(); itr3++){
              third = *itr3;
#ifdef DBG
              cout << "k = " << k << endl;
              cout << "third = " << third << endl;
#endif
              if(third > second){
#ifdef DBG2
                cout << "i = " << i << " " << flush;
                cout << "j = " << j << " " << flush;
                cout << "k = " << k << " " << flush;
                cout << endl;
#endif
                ++cnt;
                break;
              }
            }
          }
          break;
        }
      }
    }
  }

  cout << cnt << endl;
        
    

  return 0;
}
  
