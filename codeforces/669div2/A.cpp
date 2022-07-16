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
        int zero = 0;
        int one = 0;
        for (int i=0;i<n;i++) {
            if (a[i] == 0) {
                zero++;
            } else {
                one++;
            }
        }
        if (one > zero && one % 2 == 1) {
            one--;
        }
        cout << max(zero, one) << endl;
        for (int i=0;i<max(zero, one);i++) {
            if (zero >= one) {
                cout << 0;
            } else {
                cout << 1;
            }
            if (i == max(zero,one) - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }

    return 0;
}
