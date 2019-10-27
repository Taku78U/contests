#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool smaller(int a, int b){
  if(a < b){
    return true;
  } else {
    return false;
  }
}

// vector[ptr] と a を比較し、小さければOK
// dより小さい大きい最大のv[pyr]のptrを返却する
int bin_search(&vector<int> v, bool (*func)(int,int), int ptr, int d){
  int low = 0;
  int high = v.size();

  while(low < high){
    mid = (low + high) / 2;
    if(v[mid] < d){ // まだ0側にある
      high = mid - 1;
      continue;
    } else {
      low = mid;
      continue;
    }
  }
  return mid;
}

int main(){
  int n;
  vector <int> l;
  int tmp;

  cin >> n;
  cin.ignore();

  for (int i = 0; i < n; i++){
    cin >> tmp;
    v.push_back(tmp);
  }

  sort(v.begin(), v.end());

  
