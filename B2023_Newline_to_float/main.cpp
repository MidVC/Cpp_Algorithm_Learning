#include <iostream>

int main() {
    char a = 0;
    int b = 0;
    float c = 0;
    double d = 0;
    scanf("%c%d%f%lf", &a, &b, &c, &d);
    printf("%c %d %.6f %.6lf\n", a, b, c, d);
    return 0;
}
