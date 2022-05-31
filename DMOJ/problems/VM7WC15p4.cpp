#include <bits/stdc++.h>

using namespace std;

bool visited[100001];
bool visited2[100001];
int dist[100001];
int dist2[100001];
vector<pair<int, int> > adj[100001];
priority_queue<pair<int, int> > pq;

int INF = 1 << 30;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    int a,b,t;
    while (M--) {
        cin >> a >> b >> t;
        adj[a].push_back({b,t});
        adj[b].push_back({a,t});
    }
    
    for (int i=0;i<N; i++) dist[i] = INF;
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int a = pq.top().second; pq.pop();
        if (visited[a]) continue;
        visited[a] = true;
        for (auto x: adj[a]) {
            int b = x.first;
            int w  = x.second;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                pq.push({-dist[b], b});
            }
        }
    }
    for (int i=0;i<N; i++) dist2[i] = INF;
    dist2[N-1] = 0;
    pq.push({0, N-1});
    while (!pq.empty()) {
        int a = pq.top().second; pq.pop();
        if (visited2[a]) continue;
        visited2[a] = true;
        for (auto x: adj[a]) {
            int b = x.first;
            int w  = x.second;
            if (dist2[a] + w < dist2[b]) {
                dist2[b] = dist2[a] + w;
                pq.push({-dist2[b], b});
            }
        }
    }
    int max_dist = 0;
    for (int i=0; i<N; i++) {
        max_dist = max(max_dist, dist[i] + dist2[i]);
    }
    cout << max_dist << endl;


    return 0;
}
