#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    float S,R;
    cin >> S >> R;
    if (S * S > 3.14 * R * R) {
        cout << "SQUARE";
    } else {
        cout << "CIRCLE";
    }
    return 0;
}
