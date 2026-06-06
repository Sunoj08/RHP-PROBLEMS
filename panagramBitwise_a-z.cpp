#include <iostream>
#include <string>
using namespace std;

bool isPangram(string s) {
    int mask = 0;

    for (char ch : s) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            mask |= (1 << (ch - 'a'));
        }
    }

    return mask == (1 << 26) - 1;
}

int main() {
    string s;
    getline(cin, s);

    if (isPangram(s))
        cout << "Pangram\n";
    else
        cout << "Not Pangram\n";

    return 0;
}
