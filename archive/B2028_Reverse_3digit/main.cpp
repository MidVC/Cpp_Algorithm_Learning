#include <iostream>

int main() {
    int a = 0;
    scanf("%d", &a);
    int first_digit = a%10;
    int second_digit = (a/10)%10;
    int third_digit = (a/100)%10;
    printf("%d%d%d", first_digit, second_digit, third_digit);
    return 0;
}
