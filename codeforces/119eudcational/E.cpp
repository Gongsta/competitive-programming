#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int link[500001];
int counter = 0;

map<int, int> m;
int find(int a) {
    if (link[a] == a) return a;
    return link[a] = find(link[a]);
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int x, int y, int counter) {
    
}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i=0;i<=500000;i++) {
        link[i] = i;
        m[i] = i;
    }
    int t;
    cin >> t;
    vector<int> v;
    while (t--) {
        int n,x,y;
        cin >> n;
        if (n == 1) {
            cin >> x;
            v.push_back(x);

        } else {
            cin >> x >> y;
            unite()
        }

    }
    for (int i=0;i<v.size();i++) {
        cout << find(v[i]);
        if (i == v.size() -1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }

    return 0;
}
