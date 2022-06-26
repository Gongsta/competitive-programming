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
        ll sum = 0;
        int has_even = false;
        int greater_than_one = false;
        for (int i=1;i<n-1;i++) {
            if (a[i] % 2 == 1) {
                sum += a[i] / 2 + 1;

            } else {
                sum += a[i] / 2;
            }
            if (a[i] % 2 == 0) {
                has_even = true;
            }
            if (a[i] > 1) {
                greater_than_one = true;
            }
        }
        if (has_even || (greater_than_one && n > 3)) {
            cout << sum << endl;
        } else {
            cout << -1 << endl;
        }
       // test 1 3 4 3 3 1 


    }

    return 0;
}
