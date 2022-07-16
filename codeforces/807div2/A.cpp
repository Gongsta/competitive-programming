#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,x;
        cin >> n >> x;
        int h[2*n];
        for (int i=0;i<2*n;i++) {
            cin >> h[i];
        }
        sort(h, h+2*n);
        int diff = 1 << 30;
        for (int i=n;i<2*n;i++) {
            diff = min(diff, h[i] - h[i-n]);
        }
        if (diff >= x) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;

        }

    }

    return 0;
}
