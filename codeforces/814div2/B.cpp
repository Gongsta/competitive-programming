#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n,k;
        cin >> n >> k;
        bool visited[n+1];
        memset(visited, false, sizeof(visited));
        bool work = true;
        int adj[n+1];
        vector<int> roots;
        for (ll i=1;i<=n;i++) {
            if (visited[i]) continue;
            for (ll j=i+1;j<=n;j++) {
                if (visited[j]) continue;
                if (((i+k)*j) % 4 == 0) {
                    roots.push_back(i);
                    visited[i] = true;
                    visited[j] = true;
                    adj[i] = j;
                    break;
                }
            }
        }
        for (ll i=n;i>=1;i--) {
            if (visited[i]) continue;
            for (ll j=i-1;j>=1;j--) {
                if (visited[j]) continue;
                if (((i+k)*j) % 4 == 0) {
                    roots.push_back(i);
                    visited[i] = true;
                    visited[j] = true;
                    adj[i] = j;
                    break;
                }
            }
        }
        for (int i=1;i<=n;i++) {
            if (!visited[i]) {
                work = false;
                break;
            }
        }
        if (work) {
            cout << "YES" << endl;
            for (auto x: roots) {
                cout << x << " " << adj[x] << endl;
            }

        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
