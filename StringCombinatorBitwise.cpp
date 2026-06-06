#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    // Total combinations = 2^n
    for (int mask = 0; mask < (1 << n); mask++) {
        string subset = "";

        for (int i = 0; i < n; i++) {
            // Check if i-th bit is set
            if (mask & (1 << i)) {
                subset += s[i];
            }
        }

        cout << subset << "\n";
    }

    return 0;
}
