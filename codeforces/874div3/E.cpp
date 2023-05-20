#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
            a[i]--;
        }
        set<int> adj[n];
        for (int i=0;i<n;i++) {
            adj[i].insert(a[i]);
            adj[a[i]].insert(i);
        }
        bool visited[n];
        memset(visited, 0, sizeof(visited));
        int max_num = 0;
        for (int i=0;i<n;i++) {
            if (visited[i]) continue;
            max_num++;
            queue<int> q;
            visited[i] = true;
            q.push(i);
            while (!q.empty()) {
                int x = q.front(); q.pop();
                for (int e: adj[x]) {
                    if (visited[e]) continue;
                    visited[e] = true;
                    q.push(e);
                }
            }
        }

        int closed_group = 0;
        int open_group = 0;
        memset(visited, 0, sizeof(visited));
        for (int i=0;i<n;i++) {
            if (visited[i]) continue;
            queue<int> q;
            visited[i] = true;
            q.push(i);
            bool is_open_group = false;
            while (!q.empty()) {
                int x = q.front(); q.pop();
                if (adj[x].size() == 1) {
                    open_group++;
                    is_open_group = true;
                }
                for (int e: adj[x]) {
                    if (visited[e]) continue;
                    visited[e] = true;
                    q.push(e);
                }
            }
            if (!is_open_group) {
                closed_group++;
            }
        }
        if (open_group >= 1) {
            cout << closed_group + 1 << " " << max_num << endl;
        } else {
            cout << closed_group << " " << max_num << endl;
        }
    }

    return 0;
}
