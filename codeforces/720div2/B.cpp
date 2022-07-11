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
        ll min_val = 1 << 30;
        int min_val_i = 0;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            if (a[i] < min_val) {
                min_val = a[i];
                min_val_i = i;
            }
        }
        int val1 = min_val + 1;
        int val2 = 2 * min_val + 1;
        if (val2 == 2e9 + 1) {
            val2 = 2e9 - 1;
        }
        cout << n - 1 << endl;
        for (int i=0;i<min_val_i;i++) {
            if (i % 2 == 0) {
                cout << i + 1 << " " << min_val_i + 1 << " " << val1 << " " << min_val << endl;
            } else {
                cout << i + 1 << " " << min_val_i + 1 << " " << val2 << " " << min_val << endl;
            }
        }
        for (int i=min_val_i+1;i<n;i++) {
            if (i % 2 == 0) {
                cout << i + 1 << " " << min_val_i + 1 << " " << val1 << " " << min_val << endl;
            } else {
                cout << i + 1 << " " << min_val_i + 1 << " " << val2 << " " << min_val << endl;
            }
        }
    }

    return 0;
}
