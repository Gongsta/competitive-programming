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
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;

using namespace std;

ll s[200001];
vector<int> adj[200001];
ll total = 0;
bool works;

void dfs(int curr, int prev) {
    if (s[curr] == -1) {
        if (adj[curr].empty()) {
            s[curr] = s[prev];
        } else {  // Find minimum amongst child
            ll min_child = s[adj[curr][0]];
            for (auto next : adj[curr]) {
                min_child = min(min_child, s[next]);
            }
            s[curr] = min_child;
        }
    }

    if (prev == -1) {  // root node
        total += s[curr];
    } else {
        total += s[curr] - s[prev];
        if (s[curr] < s[prev]) {
            works = false;
            return;
        }
    }

    for (auto next : adj[curr]) {
        dfs(next, curr);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    works = true;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    dfs(1, -1);
    if (works) {
        cout << total << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
