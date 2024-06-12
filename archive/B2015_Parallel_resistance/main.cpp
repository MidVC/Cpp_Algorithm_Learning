#include <iostream>

int main() {
    double r1 = 0;
    double r2 = 0;
    int retval = scanf("%lf%lf", &r1, &r2);
    if (retval < 2 || r1 == 0 || r2 == 0) {
        printf("Wrong input!\n");
        return 1;
    }
    double r = 1 / (1/r1 + 1/r2);
    printf("%0.2f\n", r);
    return 0;
}
