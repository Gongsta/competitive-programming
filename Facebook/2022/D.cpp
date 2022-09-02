#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    for (int t=1;t<=tt;t++) {
        int N, M, Q;
        cin >> N >> M >> Q;
        vector<pair<int, int>> adj[N+1];
        while (M--) {
            int A,B, C;
            cin >> A >> B >> C;
            adj[A].push_back({B, C});
            adj[B].push_back({A, C});
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
