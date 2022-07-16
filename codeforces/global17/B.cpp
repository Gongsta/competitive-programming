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
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        int l = 0;
        int r = n - 1;
        for (int i=0;i<=n/2;i++) {
            if (a[l+i] != a[r-i]) {

            }
        }

    }

    return 0;
}
