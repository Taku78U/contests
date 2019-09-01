#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main(void) {
  ll n, m, a, r, c, h;
  m = 0;
  a = 0;
  r = 0;
  c = 0;
  h = 0;
  cin >> n;
  cin.ignore();
  vector<string> nameList;
  string instr;
  for(int i = 0; i < n; i++){
    cin >> instr;
    if(instr[0] == 'M'){
      m++;
      //cout << "M " << i << endl;
    }
    else if(instr[0] == 'A') a++;
    else if(instr[0] == 'R') r++;
    else if(instr[0] == 'C') c++;
    else if(instr[0] == 'H') h++;
    nameList.push_back(instr);
    cin.ignore();
  }

  ll mar;
  mar = m * a * r;
  //cout << "MAR" << mar << endl;
  ll mac;
  mac = m * a * c;
  ll mah;
  mah = m * a * h;
  ll mrc;
  mrc = m * r * c;
  ll mrh;
  mrh = m * r * h;
  ll mch;
  mch = m * c * h;
  ll arc;
  arc = a * r * c;
  ll arh;
  arh = a * r * h;
  ll ach;
  ach = a * c * h;
  ll rch;
  rch = r * c * h;
  ll sum;
  sum = mar + mac + mah + mrc + mrh + mch + arc + arh + ach + rch;
  cout << sum << endl;
  return 0;
}
  
