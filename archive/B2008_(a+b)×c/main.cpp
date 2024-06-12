#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    int retval = scanf("%d%d%d", &a, &b, &c);
    if (retval < 3) {
        printf("Wrong input!\n");
        return 1;
    }
    printf("%d", (a+b)*c);
    return 0
}
