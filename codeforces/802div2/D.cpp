#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

/*
Idea: Use prefix array? 

*/
ll v[200000];
ll prefix[200000];

ll sum(ll a, ll b) {
    if (a == 0) {
        return prefix[b];
    } else {
        return prefix[b] - prefix[a-1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> v[i];
        if (i == 0) {
            prefix[i] = v[i];
        } else {
            prefix[i] = v[i] + prefix[i-1];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        ll tj;
        cin >> tj;
        int min_pipes = 1;
        int l=0;
        int r=0;
        bool works = true;
        ll extra= 0;
        while (l < n && r < n) {
            if (sum(l,r) - extra > tj) {
                if (l == r) {
                    works = false;
                    break;
                } else {
                    extra = tj - sum(l,r-1) + extra;
                }
                min_pipes++;
                l = r;
            } else {
                r++;
            }
            // cout << l << " " << r << " " << "extra:"  << extra << endl;
        }
        
        if (works) {
            cout << min_pipes << endl;
        } else {
            cout << -1 << endl;
        }
    }


    return 0;
}
