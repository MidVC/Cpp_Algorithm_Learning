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
    int c = 100*(x*a - y*b) / (a - b);
    int pt_1 = c/100;
    int pt_2 = c%100;
    printf("%d.%d\n", pt_1, pt_2);
    return 0;
}
