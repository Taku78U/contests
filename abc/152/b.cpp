#include <stdio.h>

using namespace std;
using ll = long long;

int main(){
  char a, b;
  scanf("%c %c", &a, &b);
  ll ll_a = 0;
  ll ll_b = 0;

  for(int i = 0; i < (int) (b - (char) '0'); i++){
    ll_a *= 10;
    ll_a += (ll) (a - (char) '0');
  }
  for(int i = 0; i < (int) (a - (char) '0'); i++){
    ll_b *= 10;
    ll_b += (ll) (b - (char) '0');
  }

  if(a <= b){
    printf("%lld\n", ll_a);
  } else {
    printf("%lld\n", ll_b);
  }
  return 0;
}
