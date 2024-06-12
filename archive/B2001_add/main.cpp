#include <iostream>

int main() {
    long a = 0;
    long b = 0;
    int retval = scanf("%lld%lld", &a, &b);
    if (retval < 2) {
        printf("Wrong input!");
        return 1;
    }
    long c = a + b;
    printf("%lld", c);
    return 0;
}
