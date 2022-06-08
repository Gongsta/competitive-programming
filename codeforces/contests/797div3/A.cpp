#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    int remainder;
    int divisor;
    while (t--) {
        cin >> n;
        if (n % 3 == 0) {
            cout << n/3 << " " << n/3+ 1 << " " << n/3 -1 << endl;
        } else if (n % 3 == 1) {
            cout << n/3 << " " << n/3+ 2 << " " << n/3 -1 << endl;
        } else {
            cout << n/3 +1 << " " << n/3+ 2 << " " << n/3 - 1 << endl;
        }
    }

    return 0;
}
