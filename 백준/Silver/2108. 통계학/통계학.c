#include <stdio.h>
#include <string.h>
#include <math.h>

int mid(int ct[], int M) {
  int ctm[8001];
  memmove(ctm, ct, sizeof(int)  * 8001);
  int i;
  for(i = 0; M != 0;) {
    if(ctm[i] != 0) {
      ctm[i]--;
      M--;
    }
    else i++;
  }
  return i - 4000;
}

int fqc(int ct[]) {
  int ctf[8001];
  memmove(ctf, ct, sizeof(int)  * 8001);
  int scend = 0, max = 0;
  int fi;
  for(int i = 0; i < 8001; i++) {
    if(ctf[i] > max) {
      max = ctf[i];
    }
  }
  for(int i = 0; i < 8001; i++) {
    if(ctf[i] == max) {
      if(scend == 0) fi = i;
      if(scend == 1) return i - 4000;
      scend++;
    }
  }
  return fi - 4000;
}

int maxmin(int ct[]) {
  int ctmm[8001];
  memmove(ctmm, ct, sizeof(int)  * 8001);
  int min = 8000, max = 0;
  for(int i = 0; i < 8001; i++) {
    if(ctmm[i] != 0) {
      if(i > max) max = i;
      if(i < min) min = i;
    }
  }
  return max - min;
}

int main(void) {
  int N, sum = 0, avg;
  int inp;
  int ct[8001] = {0,};
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &inp);
    ct[inp+4000]++;
    sum += inp;
  }
  
  avg = (int)round((double)sum / N);
  
  printf("%d\n", avg);
  printf("%d\n", mid(ct, N / 2 + 1));
  printf("%d\n", fqc(ct));
  printf("%d\n", maxmin(ct));
}