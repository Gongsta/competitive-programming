#include <bits/stdc++.h>

using namespace std;

vector<int> adj[30001];
bitset<30001> visited;
unordered_set<int> offices;

int INF = 1 << 30;
int dfs(int i, int count) {
    if (offices.count(i)) return count;
    if (visited[i]) return INF;
    visited[i] = 1;
    int val = INF;
    for (int x: adj[i]) {
        val = min(val, dfs(x, count + 1));
    }
    return val;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int a,b;
    while (M--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // This is just dfs for all nodes, 
    // As soon as you reach a box office terminate.
    // Return max count
    int K;
    cin >> K;
    int x;
    while (K--) {
        cin >> x;
        offices.insert(x);
    }
    int max_count = 0;
    for (int i=1;i<=N; i++) {
        visited.reset();
        max_count = max(max_count, dfs(i, 0));
    }
    
    cout << max_count << endl;
    return 0;
}
