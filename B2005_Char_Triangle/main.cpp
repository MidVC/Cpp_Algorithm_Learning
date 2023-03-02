#include <iostream>

int main() {
    char a = 0;
    int retval = scanf("%c", &a);
    if (retval < 1 || a <= 31 || a >= 126) {
        printf("Wrong input!");
        return 1;
    }
    printf("  %c\n", a);
    printf(" %c%c%c\n", a, a, a);
    printf("%c%c%c%c%c\n", a, a, a, a, a);
    return 0;
}
