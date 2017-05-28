#include <bits/stdc++.h>

using namespace std;
using ll = long long;

char s[2000][2000];
bool e[2000][2000]; // 探索済
void resete(){
  for (int i = 0; i < 2000; i++)
    for (int j = 0; j < 2000; j++)
      e[i][j] = 0;
}

void pbarray(ll x1, ll y1, ll x2, ll y2){
  for (ll i = x1; i <= x2; i++){
    for (ll j = y1; j <= y2; j++)
      cout << e[i][j] << flush;
    cout << endl;
  }
  return;
}
  
void pcarray(ll x1, ll y1, ll x2, ll y2){
  for (ll i = x1; i <= x2; i++){
    for (ll j = y1; j <= y2; j++)
      cout << s[i][j] << flush;
    cout << endl;
  }
  return;
}
  
  

void sch(ll cx, ll cy, ll x1, ll y1, ll x2, ll y2){
  e[cx][cy] = 1;
  //pbarray(x1, y1, x2, y2);
  //pcarray(x1, y1, x2, y2);
  if(cx > x1){
    if((s[cx - 1][cy] == '1') && (e[cx-1][cy] == 0)){
      sch(cx-1, cy, x1, y1, x2, y2);
      //cout << e[cx-1][cy] << endl;
      //cout << cx <<cy << 'a' << flush;
    }
  }    
  if(cx < x2){
    if((s[cx + 1][cy] == '1') && (e[cx+1][cy] == 0)){
      sch(cx+1, cy, x1, y1, x2, y2);
      //cout << cx << cy << 'b' << flush;
    }
  }    
  if(cy > y1){
    if((s[cx][cy - 1] == '1') && (e[cx][cy-1] == 0)){
      sch(cx, cy-1, x1, y1, x2, y2);
      //cout << cx << cy << 'c' << flush;
    }
  }
  if(cy < y2){
    if((s[cx][cy + 1] == '1') && (e[cx][cy+1] == 0)){
      sch(cx, cy+1, x1, y1, x2, y2);
      //cout << cx << cy << 'd' << flush;
    }
  }
  return;
}

int main (void){
  ll n, m, q;
  cin >> n >> m >> q;
  cin.ignore();
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> s[i][j];
      //cout << s[i][j] << flush;
    }
    cin.ignore();
  }
  ll x1[q], y1[q], x2[q], y2[q];
  for (int i = 0; i < q; i++){
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    cin.ignore();
  }

  ll sum = 0;
  for (int i = 0; i < q; i++){
    resete();
    sum = 0;
    for (ll j = x1[i]-1; j <= x2[i]-1; j++){
      for (ll k = y1[i]-1; k <= y2[i]-1; k++){
        if((s[j][k] == '1') && (e[j][k] == 0)) {
          sch(j, k, x1[i]-1, y1[i]-1, x2[i]-1, y2[i]-1);
          //cout << j << k << endl;
          sum++;
        }
      }
    }
    cout << sum << endl;
  }
  return 0;
}
