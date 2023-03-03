#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    int retval = scanf("%d%d", &a, &b);
    if (retval < 2 || b == 0) {
        printf("Wrong input!\n");
        return 1;
    }
    printf("%0.9f", double(a)/b);
    return 0;
}
