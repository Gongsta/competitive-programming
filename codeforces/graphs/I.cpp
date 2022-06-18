#include <bits/stdc++.h>

using namespace std;

int a[200001];
int link[200001];
int nodes[200001];
int costs[200001];

int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b, int cost) {
    a = find(a);
    b = find(b);
    if (nodes[b] < nodes[a]) {
        swap(a,b);
    }
    link[a] = b;
    costs[b] += costs[a] + cost;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<tuple<int, int, int>> pq;
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        link[i] = i;
        nodes[i] = 1;
        costs[i] = 0;
        pq.push({-w, x, y});
    }
    int x,y,w;
    while (m--) {
        cin >> x >> y >> w;
        pq.push({-w, x, y});
    }
    while (!pq.empty()) {
        tuple<int, int, int>t = pq.top(); pq.pop();
        w = -get<0>(t);
        x = get<1>(t);
        y = get<2>(t);
        if (!same(x,y)) unite(x,y,w);
    }
    x = find(1);
    cout << costs[x] << endl;

    return 0;
}
