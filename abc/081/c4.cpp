#include <bits/stdc++.h>
using ll = long long;

using namespace std;

struct NandC{
  int n;
  int c;

  NandC(int inputted_n){
    c = 0;
    n = inputted_n;
  }

  bool operator<(const NandC &another){
    return (c == another.c) ? n < another.n : c < another.c;
  };
};

int main(){
  int n, k;
  cin >> n >> k;
  cin.ignore();

  map<int, int> m;
  int tmp;
  for (int i = 0; i < n; i++){
    cin >> tmp;
    ++m[tmp];
  }

  for(int i = 0; i < m.size(); i++){
    printf("%d:%d ", i, m[i]);
  }
  printf("\n");
  return 0;
}
