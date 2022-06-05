#include <bits/stdc++.h>

using namespace std;

bool visited[5001];
int dist[5001]; // relative to final position node
vector<pair<int, int> > adj[5001];
vector<pair<int, int> > cost;
priority_queue<pair<int, int> > pq;

int INF =  1 << 30;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,T,x,y, C;
    cin >> N >> T;
    while (T--) {
        cin >> x >> y >> C;
        adj[x].push_back({y,C});
        adj[y].push_back({x,C});
    }
    
    int K;
    cin >> K;
    while (K--) {
        cin >> x >> C;
        cost.push_back({x,C});
    }
    int D;
    cin >> D;
    
    for (int i=1;i<=N; i++) dist[i] = INF;
    dist[D] = 0;
    
    pq.push({0, D});
    while (!pq.empty()) {
        int a = pq.top().second; pq.pop();
        if (visited[a]) continue;
        visited[a] = true;
        for (auto x: adj[a]) {
            int u = x.first;
            int w = x.second;
            if (dist[a] + w < dist[u]) {
                dist[u] = dist[a] + w;
                pq.push({-dist[u], u});
            }
        }
    }
    
    int min_cost = INF;
    for (auto x: cost) {
        min_cost = min(min_cost, dist[x.first] + x.second);
    }
    cout << min_cost << endl;

    

    return 0;
}
