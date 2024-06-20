#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isRC(string s) {
    int numCount = 0;
    for (int i = 1; i < s.length(); ++i) {
        if (isdigit(s[i]) && !isdigit(s[i-1])) numCount++;
    }
    return numCount - 1; // if there are 2 num values, then it is the RC type
}

string RCtoExcel(string s) {
    // identify where is the "C"
    int location = -1;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == 'C') {
            location = i;
            break;
        }
    }

    // generate the letters representing the row
    int col = stoi(s.substr(location+1));
    string colLetters = "";
    while (col > 0) {
        char letter = ((col-1) % 26) + 'A';
        colLetters = letter + colLetters;
        col = (col-1) / 26;
    }

    return colLetters + s.substr(1, location-1);
}

string ExceltoRc(string s) {
    // identify where the numerical value starts
    int location = -1;
    for (int i = 1; i < s.length(); ++i) {
        if (isdigit(s[i])) {
            location = i;
            break;
        }
    }

    // convert the col to numerical value
    int value = 0;
    string col = s.substr(0, location);
    for (int i = 0; i < col.length(); ++i) {
        value *= 26;
        value += col[i] - 'A' + 1;
    }

    return 'R' + s.substr(location) + 'C' + to_string(value);
}

int main() {
    int n;
    cin >> n;

    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (isRC(s)) cout << RCtoExcel(s) << endl;
        else cout << ExceltoRc(s) << endl;
    }
}
