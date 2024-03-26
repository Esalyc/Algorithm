#include <stdio.h>


int main(void) {
  int numarr[5];
  int result = 1000000;
  int counts = 0;
  for(int i = 0; i < 5; i++) scanf("%d", &numarr[i]);
  for(int i = 0; i < 5; i++) {
    int temp = 1;
    counts = 0;
    while(counts < 3) {
      counts = 0;
      for(int j = 0; j < 5; j++) {
        if((numarr[i] * temp) % numarr[j] == 0) counts++;
      }
      temp++;
    }
    if(result > numarr[i] * (temp - 1)) result = numarr[i] * (temp - 1);
    
  }
  printf("%d", result);
  
}
