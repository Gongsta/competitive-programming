#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    map<int, int> m;
    while (t--) {
        m.clear();
        int n,k;
        cin >> n >> k;
        int a[n];
        int b[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b+n);
        if (n == 1) {
            cout << "YES" << endl;
        } else {
            for (int i=0;i<n-1;i++) {
                m[b[i]] = b[i+1];
            }
            
            int counter = 1;
            for (int i=0;i<n-1;i++) {
                if (!m.count(a[i]) || a[i+1] != m[a[i]]) {
                    counter++;
                }
            }
            if (counter > k) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }

    }

    return 0;
}
