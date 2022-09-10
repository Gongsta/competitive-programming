#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n,m;
        cin >> n >> m;
        int a[m];
        for (int i=0;i<m;i++) {
            cin >> a[i];
        }
        sort(a, a+m);
        vector<int> segments;
        for (int i=1;i<m;i++) {
            if (a[i] - a[i-1] - 1 > 0) {
                segments.push_back(a[i] - a[i-1] - 1);
            }
        }

        if (segments.empty()) {
            cout << 0 << endl;
        } else {
            sort(segments.begin(), segments.end(), greater<int>());
            int saved = 0;
            int days = 0;
            for (auto segment: segments) {
                if (segment - )

            }

        }

    }

    return 0;
}
