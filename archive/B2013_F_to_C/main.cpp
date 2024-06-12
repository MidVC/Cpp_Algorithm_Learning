#include <iostream>

int main() {
    double f = 0;
    int retval = scanf("%lf", &f);
    if (retval < 1) {
        printf("Wrong input!\n");
        return 1;
    }
    double c = 5*(f-32)/9;
    printf("%0.5f\n", c);
    return 0;
}
