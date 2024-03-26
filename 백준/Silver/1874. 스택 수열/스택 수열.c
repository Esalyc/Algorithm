#include <stdio.h>
int stack[100001], arr[100001], result[100001];
int size = 0, resize = 0, print = 0;
int count[200001];
void push(int data) {
  stack[size] = data;
  size++;
  count[print] = 1;
  print++; 
}
void pop(){
  result[resize] = stack[size - 1];
  resize++;
  stack[size - 1] = 0;
  size--;
  count[print] = 2;
  print++; 
}
int main(void) {
  int N, j = 0, k, max = 0;
  int check = 0, n = 1;
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }
  for(int i = 0; i < N; i++) {
    if(arr[j] > max) {
      for(k = 1; k <= arr[j] - max; k++) {
        push(n);
        n++;
      }
      max = arr[j];
    }
    pop();
    j++;
  }
  for(int i = 0; i < N; i++) {
    if(arr[i] != result[i]) {
      printf("NO");
      return 0;
    }
  }
  for(int i = 0; count[i] != 0; i++) {
    printf("%c\n", (count[i] == 1) ? '+' : '-');
  }
}