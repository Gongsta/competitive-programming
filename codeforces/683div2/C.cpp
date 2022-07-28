#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n,W;
        cin >> n >> W;
        ll w[n];
        map<ll, vector<ll>> m;
        for (int i=0;i<n;i++) {
            cin >> w[i];
            m[w[i]].push_back(i+1);
        }
        sort(w, w+n);
        ll sum = w[0];
        ll l = 0;
        ll r = 0;
        bool works = false;
        while (r<n && l<n) {
            if (sum >= ceil((double)W/(double)2) && sum <= W) {
                works = true;
                break;
            }
            if (sum > W) {
                sum -= w[l];
                l++;
                if (l > r) {
                    break;
                }
            } else {
                r++;
                if (r == n) {
                    break;
                }
                sum += w[r];
            }
        }
        vector<ll> ans;
        if (works) {
            for (int i=l;i<=r;i++) {
                ans.push_back(w[i]);
            }

        }

        
        if (ans.size() == 0) {
            cout << -1 << endl;
        } else {
            int counter = 0;
            cout << ans.size() << endl;
            for (int i=0;i<ans.size();i++) {
                if (i > 0 && ans[i] == ans[i-1]) {
                    counter++;
                } else {
                    counter = 0;
                }
                cout << m[ans[i]][counter];
                if (i == ans.size() -  1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }

    }

    return 0;
}
