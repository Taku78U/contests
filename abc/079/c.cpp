#include <bits/stdc++.h>

using ull = unsigned long long;

using namespace std;

int main (void){
  int a, b, c, d;
  scanf("%1d%1d%1d%1d", &a, &b, &c, &d);

  if(a+b+c+d==7) printf("%d+%d+%d+%d=7\n", a, b, c, d);
  else if(a+b+c-d==7) printf("%d+%d+%d-%d=7\n", a, b, c, d);
  else if(a+b-c+d==7) printf("%d+%d-%d+%d=7\n", a, b, c, d);
  else if(a+b-c-d==7) printf("%d+%d-%d-%d=7\n", a, b, c, d);
  else if(a-b+c+d==7) printf("%d-%d+%d+%d=7\n", a, b, c, d);
  else if(a-b+c-d==7) printf("%d-%d+%d-%d=7\n", a, b, c, d);
  else if(a-b-c+d==7) printf("%d-%d-%d+%d=7\n", a, b, c, d);
  else if(a-b-c-d==7) printf("%d-%d-%d-%d=7\n", a, b, c, d);

  return 0;
}
