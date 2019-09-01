#include <bits/stdc++.h>


using namespace std;

void printarray(int* a, int n){
  for(int i = 0; i < n; i++){
    cout << a[i] << " " << flush;
  }
  cout << endl;
}

int main(){
  string s;
  cin >> s;
  cin.ignore();

  int n = s.length();

  int* a;
  int* b;
  a = (int*) malloc(n * sizeof(int));
  b = (int*) malloc(n * sizeof(int));
  for (int i = 0; i < n; i++){
    a[i] = 1;
    b[i] = 0;
  }

  int* p;

  int loop;
  if(n%2 == 1){
    loop = n + 1;
  } else {
    loop = n;
  }    

  for(int i = 0; i < loop; i++){
    // 0点処理
    if(s[1] == 'L'){
      b[0] = a[1];
    } else {
      b[0] = 0;
    }
    // 最後尾処理
    if(s[n-2] == 'R'){
      b[n-1] = a[n-2];
    } else {
      b[n-1] = 0;
    }
      
    for(int j = 1; j < n - 1; j++){
      if((s[j-1] == 'L') && (s[j] == 'L') && (s[j+1] == 'L')){
        b[j] = a[j+1];
      } else if((s[j-1] == 'L') && (s[j] == 'L') && (s[j+1] == 'R')){
        b[j] = 0;
      } else if((s[j-1] == 'L') && (s[j] == 'R') && (s[j+1] == 'L')){
        b[j] = a[j+1];
      } else if((s[j-1] == 'L') && (s[j] == 'R') && (s[j+1] == 'R')){
        b[j] = 0;
      } else if((s[j-1] == 'R') && (s[j] == 'L') && (s[j+1] == 'L')){
        b[j] = a[j-1] + a[j + 1];
      } else if((s[j-1] == 'R') && (s[j] == 'L') && (s[j+1] == 'R')){
        b[j] = a[j-1];
      } else if((s[j-1] == 'R') && (s[j] == 'R') && (s[j+1] == 'L')){
        b[j] = a[j-1] + a[j+1];
      } else if((s[j-1] == 'R') && (s[j] == 'R') && (s[j+1] == 'R')){
        b[j] = a[j-1];
      }
    }

    // aとbを入れ替え
    p = a;
    a = b;
    b = p;
    for(int i = 0; i < n; i++){
      b[i] = 0;
    }
  }

  printarray(a, n);

    
      
  return 0;
}
  
