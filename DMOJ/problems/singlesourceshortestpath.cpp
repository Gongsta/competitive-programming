#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > adj[1002];
int dist[1002];
priority_queue<pair<int, int> > pq;
int processed[1002];
int INF = 1 << 30;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    
    pair<int, int> p;
    int u, v, w;
    while (M--) {
        cin >> u >> v >> w;
        p.first = v;
        p.second = w;
        adj[u].push_back(p);
        p.first = u;
        adj[v].push_back(p);
    }
    
    // Dijkstra's algorithm
    for (int i=1; i<=N; i++) dist[i] = INF;
    dist[1] = 0;
    pq.push({0,1});
    while (!pq.empty()) {
        int a = pq.top().second;
        pq.pop();
        if (processed[a]) continue;
        processed[a] = true;

        for (auto x: adj[a]) {
            int b = x.first;
            int w = x.second;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                pq.push({-dist[b], b});
            }
        }
    }
    
    for (int i=1;i<=N; i++) {
        if (dist[i] == INF) {
            cout << "-1\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
    return 0;
}
