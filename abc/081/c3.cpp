#include <bits/stdc++.h>

using namespace std;

#define MAX_NUM 200000

int c[MAX_NUM] = {0};  

int main(){
  int n, k;
  cin >> n >> k;
  cin.ignore();
  int tmp;

  for(int i = 0; i < n; i++){
    cin >> tmp;
    --tmp;
    ++c[tmp];
  }

  sort(c, c + MAX_NUM);

  int ptr = MAX_NUM - 1;

  int sum = 0;
  for(int i = 0; i < MAX_NUM; i++){
    ptr = MAX_NUM - 1 - i;
    if(i < k) continue;
    if(c[ptr] == 0) break;

    sum += c[ptr];
  }

  cout << sum << endl;

  return 0;
}
