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
        int b[n];
        int largest = 0;
        map<int, int> m;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            largest = max(largest, a[i]);
            m[a[i]]++;
        }

        for (int i=0;i<n;i++) {
            cin >> b[i];
        }
        for (int i=0;i<n;i++) {
            while (b[i] < largest) {
                b[i] *= 2;
            }
        }
        sort(b, b+n, greater<int>());
        bool works = true;
        for (int i=0;i<n;i++) {
            while (b[i] > 0) {
                if (m[b[i]] > 0) {
                    m[b[i]]--;
                    break;
                } else {
                    b[i] /= 2;
                }
            }
            if (b[i] == 0) {
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

    return 0;
}
