#include <bits/stdc++.h>

using namespace std;

int total = 0;
bool visited[1000001] = {false};
vector<int> adj[100001];

void dfs(int x) {
    if (visited[x]) return;
    else {
        visited[x] = true;
        total += 1;
        for (int i: adj[x]) {
            dfs(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, Q;
    
    cin >> N >> Q;
    
    
    int i, u,v, x;
    while (Q--) {
        cin >> i;
        if (i==1) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);

        } else {
            memset(visited, false, sizeof(visited));
            cin >> x;
            total = 0;
            dfs(x);
            cout << total << endl;

        }
    }

    return 0;
}
