#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll prefix[100000];

ll prefix_sum(int l, int r) {
    if (l == 0) {
        return prefix[r];
    } else {
        return prefix[r] - prefix[l-1];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a;
        cin >> a;
        for (int i=0;i<n;i++) {
            prefix[i] = a[i] - '0';
            if (i != 0) {
                prefix[i] += prefix[i-1];
            }
        }
        map<int, int> m;
        ll count = 0;
        m[1] = 1;
        for (int i=0;i<n;i++) {
            prefix[i] -= i;
            m[prefix[i]]++;
            count += m[prefix[i]] - 1;
        }
        
        cout << count << endl;

    }

    return 0;
}
