#include <bits/stdc++.h>

using namespace std;

int link[1000001];
int sz[1000001];
long long int pages_total[1000001];

int find(int a) {
    vector<int> v;
    while (link[a] != a) {
        a = link[a];
    }
    return a;
}
bool same(int a, int b) {
    return find(a) == find(b);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (sz[a] > sz[b]) {
        swap(a,b);
    }
    if (a != b) {
        link[a] = b;
        sz[b] += sz[a];
        pages_total[b] += pages_total[a];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,Q;
    cin >> N >> Q;
    int a,b;
    for (int i=1;i<=N;i++){
        cin >> pages_total[i];
        sz[i] = 1;
        link[i] = i;
    }
    int x;
    while (Q--) {
        cin >> x;
        if (x == 1) {
            cin >> a >> b;
            merge(a,b); // We check if they are not the same in the function

        } else if (x == 2) {
            cin >> a;
            a = find(a);
            cout << sz[a] << endl;
        } else {
            cin >> a;
            a = find(a);
            cout << pages_total[a] << endl;
        }

    }
    return 0;
}
