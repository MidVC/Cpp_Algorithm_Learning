#include <iostream>
#include <cmath>

double side_length(double xa, double ya, double xb, double yb) {
    return sqrt(pow(xb-xa, 2) + pow(yb-ya, 2));
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);

    double a = side_length(x1, y1, x2, y2);
    double b = side_length(x1, y1, x3, y3);
    double c = side_length(x2, y2, x3, y3);

    // Using Heron's formula
    double p = (a+b+c)/2;
    double s = sqrt(p * (p-a) * (p-b) * (p-c));
    printf("%.2lf", s);
    return 0;
}
