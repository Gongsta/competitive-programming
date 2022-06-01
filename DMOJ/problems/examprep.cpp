#include <bits/stdc++.h>

using namespace std;

// I GAVE UP

int link[1000001];
int vals[1000001];
int s[100001] = {1};
int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}
bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (size[a] > size[b]) swap(a,b);
    size[b] += size[a];
    link[a] = b;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,Q;
    cin >> N;
    int val;
    for (int i=1; i<=N; i++) {
        link[i] = i;
        cin >> val;
        vals[i] = val;
    }
    
    int q, a,b;
    while (Q--) {
        cin >> q;
        if (q == 1) {
            cin >> a >> b;
            if (!same(a,b)) unite(a,b);
        } else if (q==2) {
            cin >> a;
            cout << size[a] - ;
        } else {
            cin >> a;

        }

    }
    
    


    return 0;
}
