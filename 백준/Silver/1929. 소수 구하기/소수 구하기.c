#include <stdio.h>
#include <math.h>

#define MAX_TARGET 1000000

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  char isPrimeNumber[MAX_TARGET+1];
  //1은 소수가 아니라 가정
  isPrimeNumber[1] = 0;
  //1외에는 모두 소수라고 가정
  for (int i = 2; i < MAX_TARGET+1; i++)
  {
    isPrimeNumber[i] = 1;
  }

  //에라토스테네스의 체
  for (int n = 2; n <= floor(sqrt(MAX_TARGET)); n++)
  {
    //n이 소수가 아닌 경우 continue
    if (!isPrimeNumber[n]) 
    {
      continue;
    }
    //소수인 n의 배수들 모두 제거
    for (int mult = 2; n * mult <= MAX_TARGET; mult++) {
      isPrimeNumber[n*mult] = 0;
    }
  }

  //에라토스테네스의 체를 이용하여 소수들만 남은 배열 출력
  for (int i = N; i <= M; i++)
  {
    //소수인 숫자들 모두 출력
    if (isPrimeNumber[i]) 
    {
      printf("%d\n", i);
    }
  }

  return 0;
}