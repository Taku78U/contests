#include <stdio.h>
#include <limits.h>

int keta(int n){
  int ret = 0;
  while(n > 0){
    ++ret;
    n /= 10;
  }
  return ret;
}

int pow_int(int n, int cnt){
  int ret = 10;
  for(int i = 1; i < cnt; i++){
    ret *= 10;
  }
  return ret;
}

int int_msb(int n){
  int ret = n;
  int n_keta = keta(n);
  while(n_keta > 1){
    ++n_keta;
    ret /= 10;
  }
  return ret;
}

int main(){
  int n;
  scanf("%d", &n);

  int n_keta = keta(n);
  int msb = int_msb(n);
  int lsb = n % 10;

  int min, max;
  if(lsb < msb) {
    min = lsb;
    max = msb;
  } else {
    min = msb;
    max = lsb;
  }

  int table[6] = {1, 1, 10, 100, 1000, 10000};
  // 添字 間に挟まれたケタ+1
  // 0は、1ケタの場合のみ使用

  int inter_keta = n_keta - 2;
  if(n_keta == 1) { // 1ケタ
    printf("%d\n", n);
    return 0;
  }

  // 単一
  int sum = 0;
  int tanitsu[6] = {0}; // 1種類のみの場合の数
  for(int i = 0; i <= inter_keta - 1 + 1; i++){
    sum += table[i];
  }

  int sumpow = sum * sum;
  int ans1 = sumpow * 9;

  sum += table[inter_keta + 1];
  sumpow = sum * sum;
  ans1 += sumpow * min; // Nより小さい

  // 相異なる2数

  int left = 0;
  int right = 0;

  int sum2 = 0;

  if(lsb <= msb){
    for(int i = 1; i <= inter_keta; i++){
      left  += table[i];
      right += table[i];
    }
    sum2 += 9 * 8 * left * right;
    int n_inter = (n - pow_int(10, n_keta)) / 10;
    ++n_inter;
    right += n_inter;
    sum2 += lsb * (msb - 1) * right * left;
    printf("%d\n", sum + sum2);
  } else {
    for(int i = 1; i <= inter_keta; i++){
      left  += table[i];
      right += table[i];
    }
    sum2 += 9 * 8 * left * right;
    int n_inter = (n - pow_int(10, n_keta)) / 10;
    ++n_inter;
    right += n_inter;
    left += table[inter_keta + 1];
    sum2 += lsb * (msb - 1) * right * left;
    printf("%d\n", sum + sum2);
  }

  return 0;
  
}  
  
  
  
  
