#include <bits/stdc++.h>

using namespace std;

struct Infant{
  int num;
  long long rate;

  bool operator> (const Infant& another) const{
    return (rate == another.rate) ? num < another.num : rate < another.rate;
  }
};

int argmin[2*100000] = {0};
long long mymin[2*100000] = {0};
long long rate[2*100000] = {0}; // 幼児i(-1)のレート
deque<Infant> infants[2*100000]; // 添字は幼稚園番号　中身は幼児の番号

int infa_belong[2*100000] = {0};


int main(){

  // Initialize
  for(int i = 0; i < 200000; i++){
    argmin[i] = 0;
    mymin[i] = LLONG_MAX;
  }
  int n, q;
  cin >> n >> q;
  cin.ignore();

  long long tmpa;
  int tmpb;
  Infant tmp;
  for(int i = 0; i < n; i++){
    cin >> tmpa >> tmpb;
    cin.ignore();
    rate[i] = tmpa;
    --tmpb;
    infa_belong[i] = tmpb;
    tmp.num = i;
    tmp.rate = tmpa;
    infants[tmpb].push_back(tmp);
    if(mymin[tmpb] > tmpa){
      mymin[tmpb] = tmpa;
      argmin[tmpb] = i;
    }
  }
  
  for(int i = 0; i < 200000; i++){
    if(!infants[i].empty())  sort(infants[i].begin(), infants[i].end());
  }

  for(int i = 0; i < q; i++){
    int c, d;
    cin >> c >> d;
    cin.ignore();
    int you_c = infa_belong[--c];
    int you_d = infa_belong[--d];
    if(argmin[you_c] == c){
      mymin[you_c] = infants[you_c][1].rate;
      argmin[you_c] = infants[you_c][1].num;
    }
  }
  }
      
      
