#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int age;
  char name[101];
}member;

int compare(member *a, member *b){

  if (a-> age > b->age)
    return 1;
  else if (a-> age < b->age)
    return -1;
  else
    return 0;
}

int main() {
  int N;
  scanf("%d", &N);
  member* arr = (member*)malloc(N * sizeof(member));
  for(int i = 0; i < N; i++) {
    scanf(" %d %s", &arr[i].age, arr[i].name);
  }
  qsort(arr, N, sizeof(member), compare);
  for(int i = 0; i < N; i++) {
    printf("%d %s\n", arr[i].age, arr[i].name);
  }
  
  return 0;
}



