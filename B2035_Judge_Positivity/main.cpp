#include <iostream>

int main() {
    int n = 0;
    scanf("%d", &n);
    if (n > 0) {
        printf("positive\n");
    }
    else if (n == 0) {
        printf("zero\n");
    }
    else {
        printf("negative\n");
    }
    return 0;
}
