#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll prefix[200001];

ll prefix_sum(int l, int r) {
    if (l == 0) {
        return prefix[r];
    }
    return prefix[r] / prefix[l - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> prefix[i];
            if (i != 0) {
                prefix[i] *= prefix[i - 1];
            }
        }
        string s;
        cin >> s;
        int l_ptr = 0;
        int r_ptr = n - 1;
        for (char c : s) {
            cout << prefix_sum(l_ptr, r_ptr) % m << " ";
            if (c == 'L') {
                l_ptr++;
            } else {
                r_ptr--;
            }
        }
        cout << endl;
    }

    return 0;
}
