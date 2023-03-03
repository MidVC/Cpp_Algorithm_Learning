#include <bits/stdc++.h>

int determine_least_hex(int x) {
    int largest = 1;
    while(x) {
        int num = x % 10;
        if (num > largest) largest = num;
        x = x / 10;
    }
    return largest + 1;
}

int main() {

    int p, q, r;
    scanf("%d%d%d", &p, &q, &r);
    int found_appropriate_hex = false;

    int least_hex = std::max({determine_least_hex(p), determine_least_hex(q), determine_least_hex(r)});
    for (int i = least_hex; i <= 16; i++) {

        // Calculate the 10-hex value of p in i-hex
        int trans_p = 0;
        int to_multiply = 1;
        int temp_p = p;
        while(temp_p) {
            int num = temp_p % 10;
            trans_p += num * to_multiply;
            to_multiply *= i;
            temp_p /= 10;
        }

        // Calculate the 10-hex value of q in i-hex
        to_multiply = 1;
        int trans_q = 0;
        int temp_q = q;
        while(temp_q) {
            int num = temp_q % 10;
            trans_q += num * to_multiply;
            to_multiply *= i;
            temp_q /= 10;
        }

        // Calculate the 10-hex value of r in i-hex
        to_multiply = 1;
        long trans_r = 0;
        int temp_r = r;
        while(temp_r) {
            int num = temp_r % 10;
            trans_r += num * to_multiply;
            to_multiply *= i;
            temp_r /= 10;
        }

        if (long(trans_q) * trans_p == trans_r) {
            printf("%d\n", i);
            found_appropriate_hex = true;
            break;
        }
    }

    if (!found_appropriate_hex) printf("0\n");
    return 0;
}
