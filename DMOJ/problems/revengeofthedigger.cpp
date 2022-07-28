#include <bits/stdc++.h>

using namespace std;

int flow[2001];
int capacity[2001][2001];
int INF = 1 << 30;
vector<int> adj[2001];

// This is hard because the constraint is not on the edge, but on the node
// Found a solution after going on Wikipedia:https://en.wikipedia.org/wiki/Maximum_flow_problem#Maximum_flow_with_vertex_capacities
// The idea is just to add an extra edge, this is basically an additional constraint
int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(2001);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,M;
    cin >> M >> N;
    int target;
    for (int i=0;i<M;i++) {
        cin >> flow[i];
        if (flow[i] == 0) {
            target = i;
        }
    }

    for (int i=0;i<N;i++) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        adj[A].push_back(B+1000);
        adj[B+1000].push_back(A);
        capacity[A][B+1000] = flow[A];
    }
    // Do extra preprocessing for the vertex constraints
    for (int i=0;i<M;i++) {
        adj[i+1000].push_back(i);
        adj[i].push_back(i+1000);
        capacity[i+1000][i] = flow[i];
    }
    cout << maxflow(0, target+1000) << endl;

    return 0;
}
