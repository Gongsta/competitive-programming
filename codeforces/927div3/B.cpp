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
        int curr = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i == 0) {
                curr = a[i];
            } else {
                curr += 1;
                if (curr % a[i] == 0) continue;
                curr += a[i] - (curr % a[i]);
            }
        }
        cout << curr << endl;
    }

    return 0;
}
