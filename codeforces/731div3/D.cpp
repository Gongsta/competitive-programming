#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // You could have considered substraction
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        int f[n];
        f[0] = 0;
        for (int i=1;i<n;i++) {
            f[i] = ((a[i-1]^f[i-1])^a[i]) & (a[i-1]^f[i-1]);
        }
        for (int i=0;i<n;i++) {
            cout << f[i];
            if (i == n-1) {
                cout << endl;
            } else {
                cout << " ";
            }

        }

    }

    return 0;
}
