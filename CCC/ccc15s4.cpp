#include <bits/stdc++.h>
#include <tuple>
using namespace std;

vector<tuple<int, int, int> > adj[2001];
priority_queue<tuple<int, int, int> > pq;
int dist[2001][2001];
bool visited[2001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, N, M;
    cin >> K >> N >> M;
    int a,b,t,h;
    while (M--) {
        cin >> a >> b >> t >> h;
        adj[a].push_back({t,h,b});
        adj[b].push_back({t,h,a});
    }

    int A,B;
    cin >> A >> B;
    for (int i=0;i<=N;i++) {
        for (int j=0;j<=K;j++) {
            dist[i][j] = 1 << 30;
        }
    }
    dist[A][0] = 0;
    pq.push({0, 0, A});
    while (!pq.empty()) {
        int x = get<2>(pq.top());
        // cout << x << endl;
        pq.pop();
        if (visited[x]) continue;
        visited[x] = true;
        for (auto i: adj[x]) {
            int ix = get<2>(i);
            int ih = get<1>(i);
            int it = get<0>(i);
            int max_t = 1 << 30;
            int max_h = 1 << 30;
            for (int j=0;j<(K-ih);j++) {
                if ((dist[x][j] + it) < (dist[ix][j+ih])) {
                    dist[ix][j+ih] = dist[x][j] + it;
                    max_t = min(max_t, dist[ix][j+ih]);
                    max_h = min(max_h, j+ih);
                }
            }
            pq.push({-max_t, -max_h, ix});
        }
    }

    int min_t = 1 << 30;
        for (int i=0;i<K;i++) {
            if (dist[B][i] < min_t) {
                min_t = dist[B][i];
            }
        }
    if (min_t >= 1<< 30) {
        cout << "-1" << endl;
    } else {
        cout << min_t << endl;
    }

    
    return 0;
}
