#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        int x;
        int total = 0;
        while (n--) {
            cin >> x;
            total += x;
        }
        if (total <= m) {
            cout << 0 << endl;
        } else {
            cout << total - m << endl;
        }

    }

    return 0;
}
