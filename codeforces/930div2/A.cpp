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
        int ans = 1;
        while (ans * 2 <= n) {
            ans = ans * 2;
        }

        cout << ans << endl;
    }
    return 0;
}
