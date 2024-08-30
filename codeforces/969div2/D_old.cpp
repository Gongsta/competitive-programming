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

/*
1. how to compute score without ?
2. How to determine value of ?


*/

string s;
vector<int> adj[100001];
bool visited[100001];
bool iris_turn;
ll score;

void dfs(int curr, int prev, int curr_score) {
    visited[curr] = true;

    for (auto next : adj[curr]) {
        if (!visited[next]) {
            dfs(next, curr, curr_score);
        }
    }
    if (prev != -1) {
        if (s[prev] == '0' && s[curr] == '1') {
            curr_score--;
        } else if (s[prev] == '1' && s[curr] == '0') {
            curr_score++;
        }
    }
    if (curr_score != 0) {
        score++;
    }
    // cout << curr + 1 << " " << curr_score << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
        iris_turn = true;
        score = 0;
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            // cout << u << v << endl;
        }
        cin >> s;
        dfs(0, -1, 0);
        cout << score << endl;
    }

    return 0;
}
