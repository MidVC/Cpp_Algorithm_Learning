#include <iostream>

int main() {
    double pi = 3.14159;
    double r = 0;
    int retval = scanf("%lf", &r);
    if (retval < 1) {
        printf("Wrong input!\n");
        return 1;
    }
    double diameter = 2 * r;
    double perimeter = 2 * pi * r;
    double area = pi * r * r;
    printf("%0.4f %0.4f %0.4f", diameter, perimeter, area);
    return 0;
}
