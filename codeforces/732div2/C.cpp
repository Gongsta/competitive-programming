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
        int b[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b+n);

    }

    return 0;
}
