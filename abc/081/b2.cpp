#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

typedef bitset<64> ULLBitSet;

int main(){
  int n;
  vector <ULLBitSet> a;

  ull tmp_ull;

  cin >> n;
  cin.ignore();

  for(int i = 0; i < n; i++){
    cin >> tmp_ull;
    ULLBitSet tmp(tmp_ull);
    a.push_back(tmp);
  }

  ULLBitSet sum;
  for(int i = 0; i < n; i++){
    sum = sum | a[i];
  }

  int ans = 0;
  for (int i = 0; i < 64; i++){
    if(sum[i] == 0){
      ++ans;
    } else {
      break;
    }
  }

  cout << ans << endl;
  return 0;
  
}

    
