#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
bool visited[100001];
bool colored[100001];
bool works;
void dfs(int x, bool color) {
    if (visited[x]) {
        if (colored[x] != color) {
            works = false;
        }
        return;
    }
    visited[x] = true;
    colored[x] = color;
    for (int i: adj[x]) {
        dfs(i, !color);
    }
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    works = true;
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++) {
        if (visited[i]) continue;
        dfs(i, false);
    }
    if (!works) {
        cout << -1 << endl;
    } else {
        vector<int> a;
        vector<int> b;
        for (int i=1;i<=n;i++){
            if (colored[i]) {
                a.push_back(i);
            } else {
                b.push_back(i);
            }
        }
        cout << a.size() << endl;
        for (int i=0;i<a.size();i++) {
            cout << a[i];
            if (i!= a.size() -1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
        cout << b.size() << endl;
        for (int i=0;i<b.size();i++) {
            cout << b[i];
            if (i!= b.size() -1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }
    return 0;
}
