#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

/* 
1. Build Range Minimum table
2. Create the edges
3. Do BFS

*/

bool visited[250050];
int dist[250050];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n+1];
        vector<int> adj[n+1];
        for (int i=1;i<=n;i++) {
            cin >> a[i];
            visited[i] = false;
            dist[i] = 1 << 30;
        }
        for (int i=1;i<n;i++) {
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        
        queue<int> q;
        q.push(1);
        dist[1] = 0;
        while (!q.empty()) {
            int s = q.front();
            q.pop();
            visited[s] = true;
            for (auto x: adj[s]) {
                if (visited[x]) continue;
                visited[x] = true;
                dist[x] = dist[s] + 1;
                q.push(x);
            }
        }
        cout << dist[n] << endl;
    }

    return 0;
}
