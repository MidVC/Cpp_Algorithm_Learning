#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool gt (const string &a, const string &b) {
    return a+b > b+a;
}

int main() {
    int n;
    string list[21];
    
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> list[i];

    sort(list, list+n, gt);

    for (int i = 0; i < n; ++i) cout << list[i];
    cout << endl;
}
