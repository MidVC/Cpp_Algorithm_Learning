#include <iostream>

int main() {
    double a = 0;
    int retval = scanf("%lf", &a);
    if (retval < 1) {
        printf("Wrong input!\n");
        return 1;
    }
    printf("%ld\n", (long long)a);
    return 0;
}
