#include <bits/stdc++.h>

using namespace std;

int gold[100001];
vector<int> adj[100001];
bool visited[100001];

int dfs(int x, int cost) {
    if (visited[x]) return cost;
    cost = min(cost, gold[x]);
    visited[x] = true;
    for (auto i: adj[x]) {
        cost = min(cost, dfs(i, cost));
    }
    return cost;

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        cin >> gold[i];
    }
    int x,y;
    for (int i=1;i<=m;i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long long int min_cost = 0;
    for (int i=1;i<=n;i++) {
        if (visited[i]) continue;
         int cost = dfs(i, 1 << 30);
         min_cost += cost;
    }
    cout << min_cost << endl;

    return 0;
}
