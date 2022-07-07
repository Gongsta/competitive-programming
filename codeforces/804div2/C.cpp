#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll mod = 1e9+7;
ll factorial(ll n) {
    if (n <= 1) {
        return 1;
    } else {
        return (n % mod) * (factorial(n-1) % mod);
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
        int a[n];
        int one_pos = 0, zero_pos = 0;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            if (a[i] == 0) {
                zero_pos = i;
            } else if (a[i] == 1) {
                one_pos = i;
            }
        }
        int left = min(one_pos, zero_pos);
        int right = max(one_pos, zero_pos);
        if (abs(left - right) == 1) {
                cout << 1 << endl;
        } else {
            int mex = 2;
            // The greater the mex, the greater the constraint
            vector<int> q;
            for (int i=left+1;i<right;i++) {
                q.push_back(a[i]);
            }
            sort(q.begin(), q.end());
            for (auto x: q) {
                if (x == mex) {
                    mex++;
                } else {
                    break;
                }
            }
            
            ll options = right - left - 1 + n - 1 - right;
            options = options - (mex - 2) - 1;
            if (options > 0) {
                options = factorial(options);
            }
            options = options * ((right-left - 2) * factorial((mex - 2) + 1)) % mod;
            if (options == 0) {
                cout << 1 << endl;
            } else {
                cout << options << endl;
            }
            



            }
    }

    return 0;
}
