#include <bits/stdc++.h>

using namespace std;

vector<int> adj[150001];
bool visited[150001];
long long int node_count;
long long int edge_count;
void dfs(int x) {
    if (visited[x]) {
        return;
    }
    node_count++;
    visited[x] = true;
    for (auto i: adj[x]) {
        edge_count++;
        dfs(i);
    }
}
bool verify(int x) {
    node_count = 0;
    edge_count = 0;
    dfs(x);
    edge_count /= 2;
    if (edge_count != node_count * (node_count - 1) / 2) {
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    while (m--) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool works = true;
    for (int i=1;i<=n;i++) {
        if (visited[i]) continue;
        if (!verify(i)) {
            works = false;
            break;
        }
    }
    if (works) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
