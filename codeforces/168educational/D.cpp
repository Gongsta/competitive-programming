#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;

using namespace std;

vector<int> adj[200001];
ll a[200001];
ll value(int i) {  // most number of times you can decrease this node
    if (adj[i].size() == 0) {
        return a[i];
    }
    if (adj[i].size() == 1) {
        if (a[i] >= value(adj[i][0])) {
            return value(adj[i][0]);
        } else {
            return a[i] + (value(adj[i][0]) - a[i]) / 2;
        }
    }
    int max_increment = min(value(adj[i][0]), value(adj[i][1]));
    if (a[i] > max_increment) {
        return max_increment;
    }
    return a[i] + (max_increment - a[i]) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p[n];
        p[0] = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            adj[i].clear();
        }
        for (int i = 1; i < n; i++) {
            cin >> p[i];
            p[i]--;  // 0-indexed
            adj[p[i]].push_back(i);
        }
        if (adj[0].size() == 1) {
            cout << a[0] + value(adj[0][0]) << endl;
        } else {
            cout << a[0] + min(value(adj[0][0]), value(adj[0][1])) << endl;
        }
    }

    return 0;
}
