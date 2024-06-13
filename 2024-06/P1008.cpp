#include <iostream>

using namespace std;

int main() {
    // first, second, third value
    int a, b, c;

    int nums[10] = {0};
    int count = 0;

    for (a = 123; a <= 333; ++a) {
        // count the appearance of every number
        b = a * 2;
        c = a * 3;
        nums[a%10] = nums[a/10%10] = nums[a/100] = nums[b%10] = nums[b/10%10] = nums[b/100] = nums[c%10] = nums[c/10%10] = nums[c/100] = 1;

        for (int i = 1; i <= 9; ++i) {
            count += nums[i];
            nums[i] = 0;
        }

        if (count == 9) printf("%d %d %d\n", a, b, c);

        count = 0;
    }

}
