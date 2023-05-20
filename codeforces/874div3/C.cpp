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
        // If smallest number is odd, it always works
        // If smallest number is even, odd - even = odd
        if (a[0] % 2 == 1) {
            cout << "YES" << endl;
        } else {
            bool works = true;
            for (int i=0;i<n;i++) {
                if (a[i] % 2 == 1) {
                    works = false;
                    break;
                }

            }
            if (works) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

    }

    return 0;
}
