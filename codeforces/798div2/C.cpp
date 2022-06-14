#include <bits/stdc++.h>

using namespace std;

// Use DP
map<int, int> memo;
vector<int> adj[300005];

int solve(int x, int prev) {
    if (memo.count(x)) {
        return memo[x];
    }
    int total = 0;
    for (auto i: adj[x]) {
        if (i != prev) {
            total += solve(i, x) + 1;
        }
    }
    memo[x] = total;
    return memo[x];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int u,v;
        for (int i=1;i<=n;i++) {
            adj[i].clear();
        }
        memo.clear();
        for (int i=1;i<n;i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve(1, -1); // This will fill memo, where each node represents the number of children they have
        int prev = -1;
        int x = 1;
        int saved = 0;
        while (adj[x].size() > 0) {
            for (int i=0;i<adj[x].size();i++) {
                if (adj[x][i] == prev) {
                    adj[x].erase(adj[x].begin()+i);
                    break;
                }
            }
            if (adj[x].size() == 2) {
                int l = adj[x][0];
                int r = adj[x][1];
                if (adj[l].size() == adj[r].size()) {
                    if (memo[l] > memo[r]) {
                        prev = x;
                        x = r;
                        saved += memo[l];
                    } else {
                        prev = x;
                        x = l;
                        saved += memo[r];
                    }
                } else {
                    if (adj[l].size() > adj[r].size()) {
                        prev = x;
                        x = r;
                        saved += memo[l];
                    } else { // r size > l, so we go r first
                        prev = x;
                        x = l;
                        saved += memo[r];

                    }
                }
            } else if (adj[x].size() == 1) { // We can stop the infection!
                int i = adj[x][0];
                saved += memo[i];
                break;
            } else {
                break;
            }
        }
        cout << saved << endl;

        
    }

    return 0;
}
