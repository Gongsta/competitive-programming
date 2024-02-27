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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int neg = 0;
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                neg += a[i];
            } else {
                pos += a[i];
            }
        }
        cout << -neg + pos << endl;
    }

    return 0;
}
