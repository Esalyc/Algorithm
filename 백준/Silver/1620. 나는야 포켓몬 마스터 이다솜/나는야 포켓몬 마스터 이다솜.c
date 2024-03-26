#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 499

typedef struct pokemone{
  char key[21];
  int number;
  struct pokemone* next;
}pk;

typedef struct hashtable{
  pk* member[MAX_SIZE];
}ht;

unsigned int hash(char* key) {
  unsigned int hashValue = 0;
  while (*key) {
    hashValue = (hashValue << 5) + *key++ % MAX_SIZE;
  }
  return hashValue % MAX_SIZE;
}

int main(void) {
  ht table;
  int N, M;
  pk *p[MAX_SIZE] = {NULL}; // NULL로 초기화
  for(int i = 0; i < MAX_SIZE; i++) {
    table.member[i] = NULL; // 각 버킷을 NULL로 초기화
    p[i] = NULL; // 백업 포인터를 NULL로 초기화
  }

  char hn[100001][21] = {0,};
  char inp[21];
  scanf("%d%d", &N, &M);

  for(int i = 1; i <= N; i++) {
    scanf("%s", inp);
    getchar();
    unsigned int index = hash(inp);

    // 버킷이 비어 있는지 확인
    if(table.member[index] == NULL) {
      table.member[index] = (pk *)malloc(sizeof(pk)); // 새 노드에 대한 메모리 할당
      strcpy(table.member[index]->key, inp);
      table.member[index]->number = i;
      table.member[index]->next = NULL; // 다음 포인터 초기화
    } else {
      // 체이닝을 사용하여 충돌 처리
      pk *temp = table.member[index];
      while(temp->next != NULL)
        temp = temp->next;
      temp->next = (pk *)malloc(sizeof(pk)); // 새 노드에 대한 메모리 할당
      temp = temp->next;
      strcpy(temp->key, inp);
      temp->number = i;
      temp->next = NULL; // 다음 포인터 초기화
    }

    strcpy(hn[i], inp);
  }

  // 원래의 포인터 복원
  for(int i = 0; i < MAX_SIZE; i++) {
    p[i] = table.member[i];
  }

  for(int i = 1; i <= M; i++) {
    scanf("%s", inp);
    getchar();

    if(48 <= inp[0] && inp[0] <= 57) {
      printf("%s\n", hn[atoi(inp)]);
    } else {
      unsigned int index = hash(inp);  
      pk *temp = table.member[index];

      while (temp != NULL && strcmp(temp->key, inp) != 0) {
        temp = temp->next;
      }

      if(temp == NULL)
        continue;
      else
        printf("%d\n", temp->number);
    }
  }

  // 동적으로 할당된 메모리 해제
  for(int i = 0; i < MAX_SIZE; i++) {
    pk *temp = p[i];
    while(temp != NULL) {
      pk *to_free = temp;
      temp = temp->next;
      free(to_free);
    }
  }

  return 0;
}
