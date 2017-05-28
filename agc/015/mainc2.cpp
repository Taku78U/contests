#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll s[2000][2000];
ll e[2000][2000];
ll vx[2000][2000];
ll vy[2000][2000];


static void parray(ll n, ll m){
  cout << "E" << endl;
  for (int i = 0; i < n; i++){
    for (int j = 0; j< m; j++){
      cout << e[i][j] << flush;
    }
    cout << endl;
  }
  cout << "VX" << endl;
  for (int i = 0; i < n; i++){
    for (int j = 0; j< m; j++){
      cout << vx[i][j] << flush;
    }
    cout << endl;
  }
  cout << "VY" << endl;
  for (int i = 0; i < n; i++){
    for (int j = 0; j< m; j++){
      cout << vy[i][j] << flush;
    }
    cout << endl;
  }
  return;
}

int main (void){
  ll n, m, q;
  cin >> n >> m >> q;
  cin.ignore();
  char s[n][m];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> s[i][j];
      //cout << s[i][j] << flush;
    }
    cin.ignore();
  }

  //ll e[n][2000];
  ll etmp[2000];
  //ll vx[n][2000];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (j != 0) etmp[j] = etmp[j-1] + (s[i][j] == '1');
      else etmp[j] = (s[i][j] == '1');
      
      if(i != 0) e[i][j] = e[i-1][j] + etmp[j];
      else e[0][j] = etmp[j];
    }
  }
  //parray(e, n, m);
  for (int i = 0; i < n; i++){
    etmp[0] = 0;
    for (int j = 0; j < m - 1; j++){
      if (j != 0) etmp[j] = etmp[j-1] + (s[i][j] == '1' && s[i][j+1] == '1');
      else if (j== 0) etmp[0] = (s[i][j] == '1' && s[i][j+1] == '1');

      if(i != 0) vy[i][j] = vy[i-1][j] + etmp[j];
      else vy[0][j] = etmp[j];
    }
  }
  for (int i = 0; i < n - 1; i++){
    etmp[0] = 0;
    for (int j = 0; j < m; j++){
      if (j != 0) etmp[j] = etmp[j-1] + (s[i][j] == '1' && s[i+1][j] == '1');
      else if (j== 0) etmp[0] = (s[i][j] == '1' && s[i+1][j] == '1');

      if(i != 0) vx[i][j] = vx[i-1][j] + etmp[j];
      else vx[0][j] = etmp[j];
    }
  }
  //parray(v, n, m);
  //parray(n, m);
      
          
  ll x1[q], y1[q], x2[q], y2[q];
  for (int i = 0; i < q; i++){
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    cin.ignore();
    x1[i]--;
    y1[i]--;
    x2[i]--;
    y2[i]--;
  }

  ll s_0, s_x, s_y, s_xy, s_t;
  ll vx_0, vx_x, vx_y, vx_xy, vx_t;
  ll vy_0, vy_x, vy_y, vy_xy, vy_t;
  for (int i = 0; i < q; i++){
    s_0 = (x1[i] == 0 || y1[i] == 0) ? 0 : e[x1[i] - 1][y1[i] - 1];
    s_x = (y1[i] == 0) ? 0 : e[x2[i]][y1[i] - 1];
    s_y = (x1[i] == 0) ? 0 : e[x1[i] - 1][y2[i]];
    s_xy = e[x2[i]][y2[i]];
    s_t = s_xy - s_x - s_y + s_0;

    vx_0 = (x1[i] == 0 || y1[i] == 0) ? 0 : vx[x1[i] - 1][y1[i] - 1];
    vx_x = (x2[i] == 0 || y1[i] == 0) ? 0 : vx[x2[i] - 1][y1[i] - 1];
    vx_y = (x1[i] == 0) ? 0 : vx[x1[i] - 1][y2[i]];
    vx_xy = (x2[i] == 0) ? 0 : vx[x2[i] - 1][y2[i]];
    vx_t = vx_xy - vx_x - vx_y + vx_0;

    vy_0 = (x1[i] == 0 || y1[i] == 0) ? 0 : vy[x1[i] - 1][y1[i] - 1];
    vy_x = (y1[i] == 0) ? 0 : vy[x2[i]][y1[i] - 1];
    vy_y = (x1[i] == 0 || y2[i] == 0) ? 0 : vy[x1[i] - 1][y2[i] - 1];
    vy_xy = (y2[i] == 0) ? 0 : vy[x2[i]][y2[i] - 1];
    vy_t = vy_xy - vy_x - vy_y + vy_0;

    //cout << "Q = " << i << endl;
    //cout << s_t << " " << vx_t << " " << vy_t << endl;
    cout << s_t - vx_t - vy_t << endl;
  }
  
  return 0;
}
