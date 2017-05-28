#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using uint = unsigned int;

struct record{
  uint key;
  ll value;

  bool operator<( const record& right)const{
    return ;
  }

void insert(ll a, int n, int i, ll c){
  for (int j = n - 2; j >= i + 1; j--){
    a[j+1] = a[j];
  }
  a[i+1] = c;
}

void insert_s(ll a, int n, ll c){
  for(int i = n - 1; i >= 0; i--){
    if(a[i] < c) insert(a, n, i, c);
  }
  return;
}

int main (void){
  int n;

  cin >> n;
  cin.ignore();

  ll a[3 * n];
  ll b[3 * n];

  fot(int i = 0; i < 3 * n; i++){
    cin >> a[i];
    b[i] = a[i];
  }
  cin.ignore();

  sort(b, b + n);
  sort(b + (n + 1), b + (3 * n));

  ll subf = 0;
  ll subl = 0;
  ll dif = 0;

  for(int i = 0; i < n; i++){
    subf += a[i];
  }
  for(int i = 2 * n; i < 3 * n; i++){
    subl += b[i];
  }
  dif = subf - subl;

  ll tmp = 0;
  list<ll> lstf, lstl;
  for (int i = 0; i < n; i++){
    lstf.push_back(b[i]);
  }
  for (int i = 2 * n; i < 3 * n; i++){
    lstl.push_back(b[i]);
  }
  for (int i = n; i < 2 * n; i++){
    tmp = a[i];
    
  }

  return 0;
}
  
