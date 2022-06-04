#include <bits/stdc++.h>

using namespace std;

vector<int> adj[30001];
bitset<30001> visited;
int dist[30001];
unordered_set<int> offices;

// int dfs(int i, int count) {
//     if (offices.count(i)) return count;
//     if (visited[i]) return INF;
//     visited[i] = 1;
//     int val = INF;
//     for (int x: adj[i]) {
//         val = min(val, dfs(x, count + 1));
//     }
//     return val;
// }

// BFS is better because I will always find the shortest one
queue<int> q;

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
    int office_node;
    for (int i=1;i<=N; i++) {
        while (!q.empty()) {
            q.pop();
        }
        visited.reset();
        // BFS for each node
        q.push(i);
        dist[i] = 0;
        while (!q.empty()) {
            int s = q.front(); q.pop();
            if (offices.count(s)) {
                office_node = s;
                break;
            }
            for (auto x : adj[s]) {
                if (visited[x]) continue;
                visited[x] = 1;
                dist[x] = dist[s] + 1;
                q.push(x);
            }
        }
        max_count = max(max_count,dist[office_node]);
    }
    
    cout << max_count << endl;
    return 0;
}
