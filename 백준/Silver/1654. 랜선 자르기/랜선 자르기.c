#include <stdio.h>



int binsearch(int K, int N, int arr[], long long max) {
  long long low = 1;
  long long high = max;
  long long mid;
  int result;
  while (low <= high) {
    mid = (low + high) / 2;
    result = 0;
    for (int i = 0; i < K; i++) {
      result += arr[i] / mid;
    }
    
    if (result < N) { 
      high = mid - 1;
    } 
    else if (result >= N) { 
      low = mid + 1;
    }
  }
  return (low + high) / 2; 
}

int main(void) {
  int K, N, arr[10000], max = 0;
  scanf("%d%d", &K, &N);
  for (int i = 0; i < K; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] > max)
      max = arr[i];
  }
  printf("%d", binsearch(K, N, arr, max));
}