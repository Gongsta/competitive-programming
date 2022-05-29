#include <bits/stdc++.h>

using namespace std;
vector<int> adj[200001];
int val[200001];
bool visited[200001];

void dfs(int i, pair<int, int> max_num_k) {
    if (visited[i]) return max_num_k;
    visited[i] = true;
    max_num_k.first = max(max_num_k.first, val[i]);
    new_new = max_num_k;
    new_new.second += 1;
    pair<int, int> temp;
    for (int x: adj[i]) {
        temp = dfs(x, new_new);
    }
    return max_num_k;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    long long int k;
    cin >> n >> m >> k;
    
    for (int i=0;i<n; i++) {
        cin >> val[i];
    }
    int u,v;
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int min_max = numeric_limits<int>::max();
    
    for (int i=0; i<n;i++) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        p = dfs(i,p);
        min_max = min(min_max, p.second);
        if (p.first >= k - 1)

    }
    return 0;
}
