#include <bits/stdc++.h>

using namespace std;

unordered_set<int> adj[150001];

bool verify(int x) {
    bool works = true;
    for (auto i: adj[x]) {
        for (auto ii : adj[i]) {
            if (ii == x) continue;
            if (!(adj[x].count(ii))){
                works = false;
                break;
            }
        }
        if (!works) {
            break;
        }
    }
    return works;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    while (m--) {
        int a,b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    bool works = true;
    for (int i=1;i<=n;i++) {
        if (!verify(i)) {
            works = false;
            break;
        }
    }
    if (works) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
