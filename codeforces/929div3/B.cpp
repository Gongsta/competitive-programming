#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            a[i] %= 3;
        }
        sum %= 3;
        if (sum == 0) {
            cout << 0 << endl;
        } else if (sum == 1) {
            bool works = false;
            for (int i = 0; i < n; i++) {
                if (a[i] == 1) {
                    works = true;
                    break;
                }
            }
            if (works) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;

            }

        } else if (sum == 2) {
            cout << 1 << endl;

        }
    }

    return 0;
}
