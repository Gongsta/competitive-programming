#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        m++;
        int ans = 0;
        for (int k=30;k>=0 && n<m;k--) {
            if ((n >> k & 1) == (m >> k & 1)) continue;
            if (m >> k & 1) ans |= 1 << k, n|= 1 <<k;
        }
        cout << ans << endl;

    }

    return 0;
}
