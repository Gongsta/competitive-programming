#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
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
#include <vector>
// #include <unordered_map> // NEVER USE THOSE IN CP
// #include <unordered_set> // NEVER USE THOSE IN CP

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

vector<int> adj[200005];
void dfs(int u, vector<int>& st, vector<int>& last) {
    for (auto v : adj[u]) {
        if (st[v] == -1) {
            st[v] = st[u];
            last[v] = u;
            dfs(v, st, last);
        } else if (st[v] != st[u]) {
            vector<int> a;
            vector<int> b;
            for (int i = v; i != -1; i = last[i]) {
                a.push_back(i);
            }
            for (int i = u; i != -1; i = last[i]) {
                b.push_back(i);
            }
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            cout << "Possible" << endl;
            cout << a.size() << endl;
            for (auto x : a) {
                cout << x + 1 << " ";
            }
            cout << endl;
            cout << b.size() + 1 << endl;
            for (auto x : b) {
                cout << x + 1 << " ";
            }
            cout << v + 1 << endl;
            exit(0);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;
    s--;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (v != s) {
            adj[u].push_back(v);
        }
    }
    vector<int> st(n, -1);
    vector<int> last(n, -1);
    for (auto v : adj[s]) {
        st[v] = v;
        last[v] = s;
    }

    for (auto v : adj[s]) {
        dfs(v, st, last);
    }
    cout << "Impossible" << endl;

    return 0;
}
