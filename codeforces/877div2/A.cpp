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
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        if (a[0] < 0) {
            cout << a[0] << endl;
        } else {
            cout << a[n-1] << endl;

        }
    }

    return 0;
}
