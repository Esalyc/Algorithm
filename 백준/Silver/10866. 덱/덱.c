#include <stdio.h>
#include <string.h>

int Deque[20000] = {0,};
int sizeh = 10000, sizel = 10000;

void push_front(int a) {
  Deque[sizel-1] = a;
  sizel--;
}
void push_back(int a) {
  Deque[sizeh] = a;
  sizeh++;
}

void pop_front() {
  if(sizeh-sizel != 0) {
    printf("%d\n", Deque[sizel]);
    sizel++;
  }
  else printf("-1\n");
}
void pop_back() {
  if(sizeh-sizel != 0) {
    printf("%d\n", Deque[sizeh-1]);
    sizeh--;
  }
  else printf("-1\n");
}

void size() {
  printf("%d\n", sizeh-sizel);
}

void empty() {
  if(sizeh-sizel == 0) printf("1\n");
  else printf("0\n");
}

void front() {
  if(sizeh-sizel != 0) printf("%d\n", Deque[sizel]);
  else printf("-1\n");
}

void back() {
  if(sizeh-sizel != 0) printf("%d\n", Deque[sizeh-1]);
  else printf("-1\n");
}


int main(void) {
  int N, num;
  char inp[15];
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%s", inp);
    if(strcmp(inp, "push_front")==0) {
      scanf("%d", &num);
      push_front(num);
    }
    else if(strcmp(inp, "push_back")==0) {
      scanf("%d", &num);
      push_back(num);
    }
    else if(strcmp(inp, "pop_front")==0) {
      pop_front();
    }
    else if(strcmp(inp, "pop_back")==0) {
      pop_back();
    }
    else if(strcmp(inp, "size")==0) {
      size();
    }
    else if(strcmp(inp, "empty")==0) {
      empty();
    }
    else if(strcmp(inp, "front")== 0) {
      front();
    }
    else if(strcmp(inp, "back")== 0) {
      back();
    }
    
  }
  return 0;
}
