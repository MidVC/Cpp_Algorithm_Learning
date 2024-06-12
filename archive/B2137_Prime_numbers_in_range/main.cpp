#include <iostream>
#include <cmath>


int main() {
    int x, y;
    int sum = 0;
    scanf("%d%d", &x, &y);
    if (x > y) std::swap(x, y);
    if (x == 1) x++;
    for(int i = x; i <= y; i++) {
        bool prime = true;
        for(int j = 2; j <= int(sqrt(i)); j++) {
            if (i%j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) sum++;
    }
    printf("%d\n", sum);
    return 0;
}
