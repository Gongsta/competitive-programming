#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> adj[200001];
int side[200001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,b;
    memset(side, -1, sizeof(side));
    cin >> n >> m >> b;
    for (int i=0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    side[1] = 0;
    int bipartite = b;
    int small;
    int left_most_bit = 0;
    int bb=  b;
    while (bb>0)  {
        bb = bb >> 1;
        left_most_bit++;
    }
    if (__builtin_popcount(b) == 1) {
        small = 0;
    } else {
        small = 1 << ((__builtin_popcount(b)/2) - 1);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v: adj[u]) {
            if (side[v] == -1) {
                q.push(v);
                // if (side[u] == small) {
                //     side[v] = b;
                // } else {
                    side[v] = side[u] ^ b;
                // }
            } else {
                if ((side[u] ^ side[v]) == 0) {
                    if (side[v] == small || side[v] == (small ^ b)) {
                        side[v] ^= small;
                    }  else {
                        side[v] = small;
                    }
                }
                bipartite = min(bipartite, side[u] ^ side[v]);
            }
        }
    }

    cout << bipartite << endl;
    for (int i=1;i<=n;i++) {
        cout << side[i];
        if (i == n) {
            cout << endl;
        } else {
            cout << " ";
        }
    }

    return 0;
}
