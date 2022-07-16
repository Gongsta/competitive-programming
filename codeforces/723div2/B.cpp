#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        bool done = false;
        while (x >= 0) {
        if (x % 11 == 0) {
            cout << "YES" << endl;
            done = true;
            break;
        }
            x -= 111;
        }
        if (!done) {
            cout << "NO" << endl;
        }

    }

    return 0;
}
