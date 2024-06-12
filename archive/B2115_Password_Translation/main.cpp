#include <bits/stdc++.h>

int main() {
    std::string s = "";
    std::getline(std::cin, s);

    for(int i = 0; i < s.size(); i++) {
        if ((s[i] >= 66 && s[i] <= 90) || (s[i] >= 98 && s[i] <= 122)) {
            s[i] = s[i] - 1;
        }
        else if (s[i] == 65 || s[i] == 97) {
            s[i] = s[i] + 25;
        }
        printf("%c", s[i]);
    }
    return 0;
}
