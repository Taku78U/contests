#include <limits.h>
#include <stdio.h>

using namespace std;

int a[2 * 100000] = {0};

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  int min = INT_MAX;

  int cnt = 0; // 答えはminを更新した回数 ただし等号含む
  for(int i = 0; i < n; i++){
    if(a[i] <= min){
      ++cnt;
      min = a[i];
    }
  }
  printf("%d\n", cnt);
  return 0;
}
