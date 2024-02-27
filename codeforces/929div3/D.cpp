#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// Just never want 0 to appear, 0 numbers the same doesn't mean impossible

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        bool works = false;
        if (a[0] == a[1]) {
            // Find the any diff inversion where it's not equal to a[0]
            for (int i = 0; i < n; i++) {
                if (a[i] % a[0] != 0) {
                    works = true;
                    break;
                }
            }
        } else {
            works = true;
        }
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
