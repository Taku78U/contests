#include <bits/stdc++.h>

using namespace std;

struct PA{
  long long a;
  long long b;
  PA(long long in_a, long long in_b){
    a = in_a;
    b = in_b;
  }

  bool operator< (const PA& another) const{
    return (a == another.a) ? b < another.b : a < another.a;
  }
};

int main(){
  long long n;

  long long tmp_a, tmp_b;
  vector<PA> pa;
  for(long long i = 0; i < n; i++){
    cin >> tmp_a >> tmp_b;
    cin.ignore();
    pa.push_back(PA(tmp_a, tmp_b));
  }

  sort(pa.begin(), pa.end());
  if(n % 2 == 1){
    int idx = n / 2;
    long long mymin = LLONG_MAX;
    for(int i = idx; i < n; i++){
      if(mymin > pa[idx].b) mymin = pa[idx].b;
    }
    cout << mymin - pa[idx].a + 1 << endl;
  }

  long long max_a = pa[n/2 - 1].a;
  long long mymin_b = LLONG_MAX;
  for(int i = n / 2; i < n; i++){
    if(mymin_b > pa[idx].b) mymin_b = pa[idx].b;
  }
  if(n / 2 > 
