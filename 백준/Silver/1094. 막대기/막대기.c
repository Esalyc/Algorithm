#include <stdio.h>

int main(void) {
    int X, result = 0;
    scanf("%d", &X);

    while (X > 0) {
        result += X & 1;
        X >>= 1;
    }

    printf("%d", result);
    return 0;
}
