#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    int retval = scanf("%d%d", &a, &b);
    if (retval < 2 || a < b || a == 0) {
        printf("Wrong input!\n");
        return 1;
    }
    double rate = 100.0 * b / a;
    printf("%0.3f%%", rate);
    return 0;
}
