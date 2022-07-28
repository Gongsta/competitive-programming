#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        ll a[n];
        for (int i=0;i<n;i++) {
            a[i] = 2e9;
        }

        int pos[k];
        for (int i=0;i<k;i++) {
            cin >> pos[i];
            pos[i]--;
        }
        for (int i=0;i<k;i++) {
            cin >> a[pos[i]];
        }
        ll r = a[0];
        for (int i=0;i<n;i++) {
            r = min(r, a[i]);
            a[i] = min(a[i], r);
            r++;
        }
        r = a[n-1];
        for (int i=n-1;i>=0;i--) {
            r = min(r, a[i]);
            a[i] = min(a[i], r);
            r++;
        }
        for (int i=0;i<n;i++) {
            cout << a[i];
            if (i == n-1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }

    return 0;
}
