#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        set<int> s;
        unordered_map<int, int> mm;
        for (int i=0;i<n;i++) {
            int x;
            cin >> x;
            mm[x]++;
            s.insert(x);
        }
        vector<int> v;
        for (auto x: s) {
            v.push_back(x);
        }
        ll total = 0;
        vector<ll> sum;
        for (int i=0;i<v.size();i++) {
            sum.push_back(mm[v[i]]);
        }
        if (v.size() < m) {
            cout << 0 << endl;
        } else {
            for (int i=0;i<v.size()-m + 1;i++) {
                if (v[i+m - 1] - v[i] >= m) continue;
                ll local_sum = 1;
                for (int j=i;j<=i+m-1;j++) {
                    local_sum *= sum[j];
                    local_sum %= ll(1e9+7);
                }
                total += local_sum;
                total %= ll(1e9+7);
            }
            cout << total << endl;
 
        }
 
    }
 
    return 0;
}