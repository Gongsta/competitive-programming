#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    map<int, int> m;
    for (int i=0;i<n;i++) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
        if (m.count(x)) {
            m[x]++;
        } else {
            m[x] = 1;
        }
    }
    for (int i=0;i<n;i++) {
        int total = 0;
        if (m.count(v[i].second)) {
            total = m[v[i].second];
        }
        cout << n - 1 + total << " " << n -1 - total << endl;
    }
    

    return 0;
}
