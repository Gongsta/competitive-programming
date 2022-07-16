#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int q,d;
        cin >> q >> d;
        int a[q];
        for (int i=0;i<q;i++) {
            cin >> a[i];
            if (a[i] >= 10*d) {
                cout << "YES" << endl;
            } else {
                vector<int> wt;
                for (int i=0;i<d;i++) { 
                    wt.push_back(i * 10 + d);
                }
                // Do knapsack
                bool dp[a[i] + 1];
                memset(dp, false, sizeof(dp));
                dp[0] = true;
                for (int j=1; j<=a[i];j++) {
                    for (auto w: wt) {
                        if (j - w >= 0) {
                            dp[j] |= dp[j-w];
                        }
                    }
                }
                if (dp[a[i]]) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        }


    }

    return 0;
}
