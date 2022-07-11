#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        int a[2][m];
        int suffix[m];
        int prefix[m];
        for (int i=0;i<m;i++) {
            cin >> a[0][i];
        }
        for (int i=m-2;i>=0;i--) {
            a[0][i] += a[0][i+1];
        }

        for (int i=0;i<m;i++) {
            cin >> a[1][i];
            if (i>0) {
                a[1][i] += a[1][i-1];
            }
        }
        int ans = 1 << 30;
        for (int i=0;i<m;i++) {
            if (i == 0) {
                if (m > 1) {
                    ans = min(ans, a[0][i+1]);
                } else {
                    ans = 0;
                }
            } else if (i == m-1) {
                ans = min(ans, a[1][i-1]);
            } else {
                ans = min(ans, max(a[0][i+1], a[1][i-1]));
            }
        }
        cout << ans << endl;
        
    }

    return 0;
}
