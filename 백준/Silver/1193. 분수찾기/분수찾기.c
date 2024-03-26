#include <stdio.h>

int main(void) {
    int X;
    scanf("%d", &X);

    int n = 1;  // 행
    int count = 0;  // 행의 첫 분수부터의 개수

    // X가 몇 번째 행에 속하는지 찾음
    while (count + n < X) {
        count += n;
        n++;
    }

    int numerator, denominator;

    if (n % 2 == 0) {  // 행이 짝수일 때
        numerator = X - count;
        denominator = n - (X - count) + 1;
    } else {  // 행이 홀수일 때
        numerator = n - (X - count) + 1;
        denominator = X - count;
    }

    printf("%d/%d\n", numerator, denominator);

    return 0;
}
