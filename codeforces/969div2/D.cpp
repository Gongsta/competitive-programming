#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> graph[MAX_N];
string values;

pair<int, int> dfs(int node, int parent, int ones, int zeros) {
    if (values[node - 1] == '1') ones++;
    else if (values[node - 1] == '0') zeros++;

    if (graph[node].size() == 1 && node != 1) { // Leaf node
        int weight = ones - zeros;
        return {weight != 0, weight != 0};
    }

    vector<pair<int, int>> child_results;
    for (int child : graph[node]) {
        if (child != parent) {
            child_results.push_back(dfs(child, node, ones, zeros));
        }
    }

    if (values[node - 1] == '?') {
        int max_score = 0, min_score = INT_MAX;
        for (int val = 0; val <= 1; val++) {
            int current_score = 0;
            for (auto [child_max, child_min] : child_results) {
                current_score += (val == 0) ? child_min : child_max;
            }
            max_score = max(max_score, current_score);
            min_score = min(min_score, current_score);
        }
        return {max_score, min_score};
    } else {
        int score = 0;
        for (auto [child_max, child_min] : child_results) {
            score += child_max; // or child_min, they're the same for determined nodes
        }
        return {score, score};
    }
}

int solve_tree_game() {
    return dfs(1, 0, 0, 0).first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            graph[i].clear();
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cin >> values;

        cout << solve_tree_game() << "\n";
    }

    return 0;
}
