#include <stdio.h>
#include <math.h>


int main(void) {
  double x1, y1, r1, x2, y2, r2;
  double len, PI = M_PI;
  scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2);
  x2 -= x1; y2 -= y1;
  x1 = y1 = 0;
  len = sqrt(pow(fabs(x2), 2) + pow(fabs(y2), 2));
  if(r1>r2) {
    double tmp;
    x1 = x2; x2 = 0;
    y1 = y2; y2 = 0;
    tmp = r1; r1 = r2; r2 = tmp;
  }
  if(r1+r2 <= len) {
    printf("0.000");
    return 0;
  }
  else if(r2>=len+r1) {
    printf("%.3lf", pow(r1, 2) * PI);
    return 0;
  }
  else {
    double theta1, theta2, d; 
    d = sqrt(4*pow(r1, 2)*pow(r2, 2)-pow(r1*r1 + r2*r2 - len*len, 2)) / len;
    theta1 = acos((2 * pow(r1, 2) - pow(d, 2)) / (2 * pow(r1, 2)));
    theta2 = acos((2 * pow(r2, 2) - pow(d, 2)) / (2 * pow(r2, 2)));
    if(pow(r2, 2) > pow(r1, 2) + pow(len, 2)) theta1 = 2*PI - theta1;
    
    printf("%.3lf", 0.5*pow(r1, 2)*theta1+0.5*pow(r2, 2)*theta2 - len * d / 2);
  }
  return 0;
}