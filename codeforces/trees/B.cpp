#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];

double dfs(int curr, int prev) {
    int child = 0;
    double total = 0;
    for (int x: adj[curr]) {
        if (x != prev) {
            total += dfs(x, curr);
            child++;
        }
    }
    double count = adj[curr].size();
    if (curr != 1) {
        count--;
    }
    if (child == 0) {
        return 0;
    }
    return 1.0 + (total / count);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    n--;
    while (n--) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    double ans = dfs(1, -1);
    cout << setprecision(12) << fixed << ans << endl;

    return 0;
}
