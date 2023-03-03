#include <iostream>
#include <cmath>

int main() {
    double xa, ya, xb, yb;
    scanf("%lf%lf%lf%lf", &xa, &ya, &xb, &yb);
    double distance = sqrt(pow((xa-xb), 2) + pow((ya-yb), 2));
    printf("%.3lf", distance);
    return 0;
}
