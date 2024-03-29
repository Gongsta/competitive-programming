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

        bool positive = false;

        int count = 0;
        int curr_max = 0;
        bool duplicate = false;
        int min_dist = 1 << 30;
        for (int i=0;i<n;i++) {
            if (i > 0) {
                min_dist = min(min_dist,a[i] - a[i-1]);
            }
            if (a[i] > min_dist) {
                 break;
            }
            count++;
        }
        cout << max(1, count) << endl;

    }

    return 0;
}
