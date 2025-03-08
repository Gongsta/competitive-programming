#include <bits/stdc++.h>

using namespace std;

int dist[500][500];
int adj[500][500];

int INF = 20002;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int temp = N;
    temp--;
    int u, v; 
    
    
    // Definitely need DP for this problem 
    if (N > 500){
        vector<int> vec[200001];
        while (temp--) {
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
            
        }

    } else {
        while (temp--) {
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (i == j) dist[i][j] = 0;
                else if (adj[i][j]) dist[i][j] = 1;
                else dist[i][j] = INF;
            }
        }
        for (int k = 1; k <=N; k++) {
            for (int i = 1; i <=N; i++) {
                for (int j = 1; j <=N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        
        // i, j, k are the starting positions
        map<int, int> m;
        for (int k = 1; k<=N; k++) {
            for (int i = 1; i <=N; i++) {
                for (int j = 1; j <=N; j++) {
                    int best = INF;
                    int best_node = 1;
                    for (int x=1; x<=N; x++) {
                        if (dist[x][i] + dist[x][j] + dist[x][k] < best) {
                            best = dist[x][i] + dist[x][j] + dist[x][k];
                            best_node = x;
                        }
                    }
                    if (!m.count(best_node)) {
                        m[best_node] = 1;
                    } else {
                        m[best_node] += 1;
                    }
                }
            }
        }
        
        for (int i=1; i<=N; i++) {
            if (!m.count(i)) {
                cout << 0;
            } else {
                cout << m[i];
            }
            if (i!=N) {
                cout << " ";
            } else {
                cout << endl;
            }
        }

    }

    
    return 0;
}
