#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    int u,v;
    int count[n];
    int total = 0;
    memset(count, 0, sizeof(count));
    while (m--) {
        cin >> u >> v;
        u--;
        v--;
        if (u > v) {
            swap(u,v);
        }
        count[u]++;
    }
    for (int i=0;i<n;i++) {
        if (count[i] > 0) {
            total++;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (x == 2) {
            cin >> u >> v;
            u--;
            v--;
            if (u > v) {
                swap(u,v);
            }
            count[u]--;
            if (count[u] == 0) {
                total--;
            }

        } else if (x == 1) {
            cin >> u >> v;
            if (u > v) {
                swap(u,v);
            }
            u--;
            v--;
            count[u]++;
            if (count[u] == 1) {
                total++;
            }
        } else {
            cout << n - total << endl;
        }

    }

    return 0;
}
