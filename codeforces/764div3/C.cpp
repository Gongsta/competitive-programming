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
        bool used[n+1] = {false};
        for (int i=0;i<n;i++) {
            cin >> a[i];
            while (a[i] > n) {
                a[i] /= 2;
            }
        }
        sort(a,a+n, greater<int>());
        bool works = true;
        for (int i=0;i<n;i++) {
            while (used[a[i]] && a[i] > 0) {
                a[i] /= 2;
            }
            if (a[i] == 0) {
                works = false;
                break;
            } else {
                used[a[i]] = true;
            }
        }
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
