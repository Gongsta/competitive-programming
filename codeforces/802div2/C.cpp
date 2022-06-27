#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

/*
4 -4 4 -4
8 0 8 0 (+4)
0 -8 0 0 (+8)
-8 -8 0 0 (+8)
-8 -8 -8 -8 (+8)
0 0 0 0 (+8)

1 -2 3 -4 5

*/

ll a[200000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        ll total = 0;
        for (int i=1;i<n;i++) {
            total += abs(a[i] - a[i-1]);
            if (a[i] < a[i-1]) {
                a[0] += a[i] - a[i-1];
            }
        }
        total += abs(a[0]);
        cout << total << endl;

        

    }

    return 0;
}
