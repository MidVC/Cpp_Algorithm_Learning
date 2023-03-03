#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double delta = b*b - 4*a*c;
    if (delta < 0) {
        printf("No answer!\n");
    }
    else if (delta == 0) {
        double sol = -b / (2*a);
        printf("x1=x2=%.5lf\n", sol);
    }
    else {
        double sol1 = (-b + sqrt(delta)) / (2*a);
        double sol2 = (-b - sqrt(delta)) / (2*a);
        if (sol1 > sol2) {
            std::swap(sol1, sol2);
        }
        printf("x1=%.5lf;x2=%.5lf\n", sol1, sol2);
    }
    return 0;
}
