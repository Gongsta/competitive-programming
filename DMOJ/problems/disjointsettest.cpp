#include <bits/stdc++.h>

using namespace std;

int link[100001];
int s[100001] = {1};
bitset<1000001> arr;
unordered_set<int> vals;
int find(int x) {
    while(x != link[x]) x = link[x];
    return x;
}
bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (s[u] < s[v]) swap(u,v);
    s[u] += s[v];
    link[v] = u;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    for (int i=1;i<=N;i++) {
        link[i] = i; // At first, all vertices are simply linked to themselves
        vals.insert(i);
    }

    int u,v;
    for (int i=1; i<=M; i++) {
        cin >> u >> v;
        if (!same(u,v)) {
            unite(u,v);
            vals.erase(u);
            vals.erase(v);
            arr[i] = 1;
        }
    }
    
    if (!vals.empty()) {
        cout << "Disconnected Graph\n";
        return 0;
    }
    
    for (int i=1; i<=M; i++) {
        if (arr[i]) {
            cout << i << "\n";
        }
    }

    return 0;
}
