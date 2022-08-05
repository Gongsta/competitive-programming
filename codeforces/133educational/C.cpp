#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        // 3 ways
        int m;
        cin >> m;
        ll a[2][m];
        for (int i=0;i<2;i++) {
            for (int j=0;j<m;j++) {
                cin >> a[i][j];
            }
        }

        ll time1 = 0;
        ll time2 = 0;
        ll time3 = 0;

        // Way 1
        for (int j=1;j<m;j++) {
            time1 = max(time1+1, a[0][j]+1);
        }
        time1 = max(time1+1, a[1][m-1]+1);
        for (int j=m-2;j>=0;j--) {
            time1 = max(time1+1, a[1][j]+1);
        }

        // Way 2
        time2 = max(time2+1, a[1][0]+1);
        for (int j=1;j<m;j++) {
            time2 = max(time2+1, a[1][j]+1);
        }
        time2 = max(time2+1, a[0][m-1]+1);
        for (int j=m-2;j>0;j--) {
            time2 = max(time2+1, a[0][j]+1);
        }

        // Way 3
        ll mod = 0;
        ll counter = 1;
        ll i = 0;
        ll j = 0;
        while (counter < 2*m) {
            if (mod == 0) {
                time3 = max(time3+1, a[++i][j]+1);
            } else if (mod == 1) {
                time3 = max(time3+1, a[i][++j]+1);
            } else if (mod == 2) {
                time3 = max(time3+1, a[--i][j]+1);
            } else if (mod == 3) {
                time3 = max(time3+1, a[i][++j]+1);
            }
            mod++;
            mod %= 4;
            counter++;
        }
        cout << min(time1, min(time2, time3)) << endl;

    }

    return 0;
}
