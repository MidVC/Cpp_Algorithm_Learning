#include <iostream>

int main() {
    int x = 0;
    int a = 0;
    int y = 0;
    int b = 0;
    int retval = scanf("%d%d%d%d", &x, &a, &y, &b);
    if (retval < 4) {
        printf("Wrong input!");
        return 1;
    }
    printf("%0.2f", double(x*a-y*b)/(a-b));
    return 0;
}
