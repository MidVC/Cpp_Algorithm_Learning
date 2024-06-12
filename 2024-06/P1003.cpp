#include <iostream>

using namespace std;

int main() {
    // a, b, c, d are top left point, and length and width of the carpet
    int a[10000], b[10000], c[10000], d[10000];

    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    cin >> x >> y;

    for (int i = n-1; i >= 0; --i) {
        if (x >= a[i] &&
            x <= a[i] + c[i] &&
            y >= b[i] &&
            y <= b[i] + d[i]) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
