#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int sz[1001];
int link[1001];

int find(int a) {
    if (link[a] == a) {
        return a;
    } else {
        return link[a] = find(link[a]);
    }
}
bool same(int a, int b) {
    return find(a) == find(b);
}

int unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (sz[a] > sz[b]) swap(a,b);
    sz[b] += sz[a];
    link[a] = b;
    return b;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,d;
    cin >> n >> d;
    for (int i=1;i<=n;i++) {
        link[i] = i;
        sz[i] = 1;
    }
    set<int> s;
    int max_sz = 1;
    int links = 0;
    int max_node = 1;
    set<int, greater<int>> sizes;
    for (int i=1;i<=d;i++) {
        int x,y;
        cin >> x >> y;
        if (!same(x,y)) {
            links++;
            if (s.count(find(x)) && s.count(find(y))) { // One of them need to be erased
                s.erase(find(x));
                s.erase(find(y));
            } 
            s.insert(unite(x, y));
            sizes.clear();
            for (auto ss: s) {
                sizes.insert(sz[ss]);
            }
        } 
        int remaining = i - links + 1;
        int ans = 0;
        for (auto f: sizes) {
            if (remaining == 0) break;
            remaining--;
            if (ans == 0) {
                ans += f - 1;
            } else {
                ans += f;
            }
        }
        cout << ans + remaining << endl;
        
    }

    return 0;
}
