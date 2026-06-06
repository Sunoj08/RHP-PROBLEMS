#include <iostream>
using namespace std;

bool isDigitPangram(string s) {
    int mask = 0;

    for (char ch : s) {
        if (ch >= '0' && ch <= '9') {
            int digit = ch - '0';
            mask |= (1 << digit);
        }
    }

    // Check if all 10 bits are set (i.e., 1111111111 in binary)
    return mask == (1 << 10) - 1;
}

int main() {
    string s;
    cin >> s;

    if (isDigitPangram(s))
        cout << "Contains all digits (0-9)\n";
    else
        cout << "Does NOT contain all digits\n";

    return 0;
}
