//  Copyright ? 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 1000005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
ll T;

const ll LIM = 4e5;
ll fact[LIM + 5];
ll finv[LIM + 5];

ll fastpow( ll b , ll e )
{
  ll ans = 1;
  while( e > 0 )
  {
    if( e & 1 )
      ans = ( ans * b ) % MOD;

    b = ( b * b ) % MOD;
    e >>= 1;
  }
  return ans;
}

ll nCk( ll n , ll k )
{
  return ( fact[n] * ( ( finv[k] * finv[n - k] ) % MOD ) ) % MOD;
}

void calcFact() {
  fact[0] = finv[0] = 1;
  for( ll i = 1; i <= LIM; i ++ )
    fact[i] = ( fact[i - 1] * i ) % MOD;

  finv[LIM] = fastpow( fact[LIM] , MOD - 2 );

  for( ll i = LIM - 1; i >= 1; i -- )
    finv[i] = ( finv[i + 1] * ( i + 1 ) ) % MOD;
}

ll solve( ll N , ll M , ll K ) {
  if( N == K )
    return 0;
  ll ans = nCk( N , K );
  ans = ( ans * fastpow( M , N - K ) );
  return ans % MOD;
}
int main(){
  optimiza_io
      calcFact();
  ll N,M,K;
  cin>>N>>M>>K;
  ll ans=0;
  while(K>=0){
    ll tmp=nCk(N-1,K);
    tmp=(tmp*M)%MOD;
    tmp=(tmp*fastpow(M-1,N-K-1));
    ans=(ans+tmp)%MOD;
    K--;
  }
  cout<<ans;
  return 0;
}
