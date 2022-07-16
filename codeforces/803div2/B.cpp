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
            cin >> a[i];
        }
        int count = 0;
        for (int i=1;i<n-1;i++) {
            if (a[i] > a[i-1] + a[i+1]) {
                count++;
            }
        }
        if (k > 1) {
            cout << count << endl;
        } else {
            cout << (n - 2) / 2 + (n % 2) << endl;
        }

    }

    return 0;
}
