#include <iostream>

int main() {
    int h = 0;
    int r = 0;
    scanf("%d%d", &h, &r);
    double v = 3.14 * (r/10.0) * (r/10.0) * (h/10.0);
    int bucket_needed = int((20+v) / v);
    printf("%d\n", bucket_needed);
    return 0;
}
