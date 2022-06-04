#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, S;
    cin >> R >> S;
    int total = R * 8 + S * 3;

    if (total - 28 < 0)  {
        cout << 0 << endl;
    } else {
        cout << total - 28 << endl;
    }

    return 0;
}