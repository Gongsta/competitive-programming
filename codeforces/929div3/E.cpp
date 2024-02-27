#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll prefix[100001];

ll sum(int i, int n) {
    return (n) * (n + 1) / 2 - (i - 1) * (i) / 2;
}

ll prefix_sum(int l, int r) {
    if (l == 0) {
        return prefix[r];
    }
    return prefix[r] - prefix[l - 1];
}

int bin_search(int l, int r, int u) {
    int target;
    int n = r;
    int l_beg = l;
    if (l == 0) {
        target = u;
    } else {
        target = u + prefix[l - 1];
    }

    int ans = l_beg;
    ll curr_max = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (prefix[mid] == target) {
            return mid;
        }
        if (prefix[mid] > target) {
            int diff = prefix[mid] - target;
            if (sum(0, u) - sum(0, diff - 1) > curr_max) {
                curr_max = sum(0, u) - sum(0, diff - 1);
                ans = mid;
            }
            r = mid - 1;
        } else {
            if (sum(u - prefix_sum(l_beg, mid) + 1, u) >= curr_max) {
                curr_max = sum(u - prefix_sum(l_beg, mid) + 1, u);
                ans = mid;
            }
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            prefix[i] = a[i];
            if (i != 0) {
                prefix[i] += prefix[i - 1];
            }
        }

        int q;
        cin >> q;
        while (q--) {
            int l, u;
            cin >> l >> u;
            int ans;
            ans = bin_search(l - 1, n, u);
            cout << min(ans + 1, n) << " ";
        }
        cout << endl;
    }

    return 0;
}
