#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        int total = n * (n-1) / 2;
        int nn = n;
        while (total > k) {
            nn--;
            total -= nn;
            total += (n -nn - 1);
        }
        if (total == k) {
            cout << "YES" << endl;
            for (int i=0;i<nn;i++) {
                cout << "-1 ";
            }
            if (nn == n) {
                cout << endl;

            }
            for (int i=nn;i<n;i++) {
                cout << 1;
                if (i == n-1) {
                    cout << endl;
                } else {
                    cout << " ";
                }

            }

        } else {
            cout << "NO" << endl;
        }


    }

    return 0;
}
