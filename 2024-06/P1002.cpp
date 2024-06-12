#include <iostream>

using namespace std;

const int moveX[9] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int moveY[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    long long dp[30][30] = {0};
    bool horseBlock[30][30] = {0};

    int x, y, horseX, horseY;
    scanf("%d%d%d%d", &x, &y, &horseX, &horseY);

    x += 2;
    y += 2;
    horseX += 2;
    horseY += 2;

    dp[2][1] = 1;

    for (int i = 0; i <= 8; ++i) {
        horseBlock[horseX + moveX[i]][horseY + moveY[i]] = true;
    }

    // dp
    for (int i = 2; i <= x; ++i) {
        for (int j = 2; j <= y; ++j) {
            if (horseBlock[i][j]) continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    printf("%lld\n", dp[x][y]);

}