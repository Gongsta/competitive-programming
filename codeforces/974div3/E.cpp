#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;

using namespace std;

void dijkstras(vector<vector<ll>>& dist, int start, vector<pair<int, int>> adj[], int n, vector<bool>& a) {
    priority_queue<pair<int, pair<int, bool>>, vector<pair<int, pair<int, bool>>>, greater<pair<int, pair<int, bool>>>> pq;
    pq.push({0, {start, a[start]}});
    bool visited[2][n + 1];
    memset(visited, 0, sizeof(visited));
    while (!pq.empty()) {
        int u = pq.top().second.first;
        bool has_horse = pq.top().second.second;
        pq.pop();
        if (visited[has_horse][u]) {
            continue;
        }
        visited[has_horse][u] = true;

        for (auto x : adj[u]) {
            int v = x.first;
            ll w = x.second;

            if (has_horse) {
                w /= 2;
            }
            bool new_h = has_horse || a[v];
            if (dist[has_horse][u] + w < dist[new_h][v]) {
                dist[new_h][v] = dist[has_horse][u] + w;
                pq.push({dist[new_h][v], {v, new_h}});
            }
        }
    }
}

ll INF = 1e15;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;
        vector<bool> a(n + 1, false);
        for (int i = 0; i < h; i++) {
            int idx;
            cin >> idx;
            a[idx] = true;
        }
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<vector<ll>> dist1(2, vector(n + 1, INF));
        vector<vector<ll>> dist2(2, vector(n + 1, INF));

        dist1[a[1]][1] = 0;
        dist2[a[n]][n] = 0;
        dijkstras(dist1, 1, adj, n, a);
        dijkstras(dist2, n, adj, n, a);

        ll min_time = INF;
        for (int i = 1; i <= n; i++) {
            ll time = max(min(dist1[0][i], dist1[1][i]), min(dist2[0][i], dist2[1][i]));
            min_time = min(min_time, time);
        }

        if (min_time == INF) {
            cout << -1 << endl;
        } else {
            cout << min_time << endl;
        }
    }

    return 0;
}
