#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        int a[n];
        ll sum = 0;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            sum += a[i];
        }
        // Check even
        ll sum_even = 0;
        for (int i=0;i<n;i+=2) {
            sum_even += a[i];
        }

        if (2 * (sum_even - ceil(n / 2)) <= sum) {
            for (int i=0;i<n;i++) {
                if (i % 2 == 0) {
                    cout << 1;
                } else {
                    cout << a[i];
                }
                if (i == n-1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        } else {
            for (int i=0;i<n;i++) {
                if (i % 2 == 1) {
                    cout << 1;
                } else {
                    cout << a[i];
                }
                if (i == n-1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }


    }

    return 0;
}
