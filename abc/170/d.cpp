#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();

  vector<int> a;
  int tmp;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    a.push_back(tmp);
  }

  if(n == 1){
    cout << 1 << endl;
    return 0;
  }
  sort(a.begin(), a.end());

  bool same = false;
  int cnt = 0;
  for(int i = 0; i < a.size(); i++){
    if(i < a.size() - 1 && a[i] == a[i+1]){
      same = true;
      continue; // 同じものは数えない
    }
    if(same) { // 同じものの最終要素
      same = false;
      continue;
    }

    //int lim = ceil(sqrtl(a[i])+1);
    int lim = a[i] / 2;
    bool an = true;
    for(int j = 0; a[j] <= lim && a[j] < a[i]; j++){
      if(a[i] % a[j] == 0){
        an = false;
        break;
      }
    }
    if(an){
      //cout << a[i] << " " << flush;
      ++cnt;
    }
  }

  //cout << endl;
  cout << cnt << endl;
  return 0;
}
  
  
