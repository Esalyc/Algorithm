#include <stdio.h>

int main(void) {
  int T, west, east;
  scanf("%d", &T);
  for(int i = 0; i < T; i++) {
    double fact = 1, fact2 = 1;
    scanf("%d%d", &west, &east);
    for(int j = east; j > west; j--) {
      fact = fact * j;
    }
    for(int j = east - west; j > 0; j--) {
      fact2 = fact2 * j;
    }
    printf("%.0lf\n", fact / fact2);
  }

}
