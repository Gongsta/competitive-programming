#include <bits/stdc++.h>

using namespace std;

vector<int> adj[20001];
bool visited[20001];
queue<int> q;

void dfs(int n) {
    if (visited[n]) return;
    visited[n] = true;
    for (auto u: adj[n]) {
        dfs(u);
    }
    q.push(n);
}

int main() {
    // Use topological sorting
    int N;
    cin >> N;
    
    // Store in a digraph
    int a,b;
    for (int i=1; i<=N; i++) {
        cin >> a;
        while (a--) {
            cin >> b;
            adj[i].push_back(b);
        }
        dfs(i);
    }
    
    for (int i=1; i<=N; i++) {
        dfs(i);
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}