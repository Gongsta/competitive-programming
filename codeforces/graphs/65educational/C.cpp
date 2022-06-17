#include <bits/stdc++.h>

using namespace std;
// Solved with a segment tree
int adj[500001];
int friends[500001];

int find(int a) {
    while (a != adj[a]) a = adj[a];
    return a;
}
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (friends[b] < friends[a]) swap(a,b);
    adj[a] = b;
    friends[b] += friends[a];
}
int count_friends(int a) {
    while (a != adj[a]) a = adj[a];
    return friends[a];
}

bool compare(int a, int b) {
    return find(a) == find(b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    int k;
    for (int i=1; i<=n;i++) {
        adj[i]= i;
        friends[i] = 1;
    }

    while (m--) {
        cin >> k;
        if (k == 0) continue;
        if (k == 1) {
            int x;
            cin >> x;
        } else {
            k-=2;
            int a,b;
            cin >> a >> b;
            unite(a, b);
            int c;
            while (k--) {
                cin >> c;
                unite(b, c);
            }
        }
    }
    for (int i=1;i<=n;i++) {
        cout << count_friends(i);
        if (i != n) {
            cout << " ";
        } else {
            cout << endl;
        }
    }


    return 0;
}
