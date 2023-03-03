#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int sum_eat = 0;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    // First turn
    sum_eat += a % 3;
    e += a / 3;
    b += a / 3;
    a = a / 3;

    // Second turn
    sum_eat += b % 3;
    a += b / 3;
    c += b / 3;
    b = b / 3;

    // Third turn
    sum_eat += c % 3;
    b += c / 3;
    d += c / 3;
    c = c / 3;

    // Fourth turn
    sum_eat += d % 3;
    c += d / 3;
    e += d / 3;
    d = d / 3;

    // Fifth turn
    sum_eat += e % 3;
    d += e / 3;
    a += e / 3;
    e = e / 3;

    printf("%d %d %d %d %d\n%d", a, b, c, d, e, sum_eat);
    return 0;
}
