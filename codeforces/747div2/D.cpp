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
        set<int> adj[2*n+1];
        int side[2*n+1];
        memset(side, -1, sizeof(side));
        while (m--) {
            int i,j;
            string s;
            cin >> i >> j >> s;
            i--;
            j--;
            if (s == "imposter") {
                adj[i].insert(j);
                adj[j].insert(i);
            } else {
                adj[i].insert(j+n);
                adj[j+n].insert(j);
                adj[j].insert(j+n);
                adj[j+n].insert(i);
            }
        }
        bool bipartite = true;
        queue<int> q;
        int total = 0;
        for (int i=0;i<n;i++) {
            int zero = 0;
            int one = 0;
            if (side[i] == -1) {
                q.push(i);
                side[i] = 0;
                zero++;
                while (!q.empty()) {
                    int x = q.front();
                    q.pop();
                    for (auto v: adj[x]) {
                        if (side[v] == -1) {
                            side[v] = side[x] ^ 1;
                            if (v < n) {
                                if (side[v] == 1) {
                                    one++;
                                } else {
                                    zero++;
                                }
                            }
                            q.push(v);
                        } else {
                            if (side[x] == side[v]) {
                                bipartite = false;
                                break;
                            }

                        }
                    }
                }
                total += max(one,zero);

            }
        }
        if (!bipartite) {
            cout << -1 << endl;
        } else {
            cout << total << endl;
        }

    }

    return 0;
}
