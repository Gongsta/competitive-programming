#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


ll dp[200001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        
    int n,k;
    cin >> n >> k;
    vector<int> v;
    v.push_back(0);
    for (int K=k;K<=n;K++) {
        vector<int> temp;
        for (auto x: v) {
            for (int i=1;i<=n;i++) {
                if (x + i * K > n) break;
                dp[x+i*K]++;
                temp.push_back(x+i*K);
            }
        }
        v = temp;
    }

    for (int i=1;i<=n;i++) {
        cout << dp[i] % 998244353;
        if (i == n) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    return 0;
}
