#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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

const int MAX = 2e5 + 1;
int cnt[MAX];
bool visited[MAX];
int ans[MAX];

vector<int> unrooted_adj[MAX];
vector<int> adj[MAX];

void build_rooted(int i) {
    for (int x : unrooted_adj[i]) {
        if (visited[x]) {
            continue;
        }
        adj[i].push_back(x);
        visited[x] = true;
        build_rooted(x);
    }
}

int build_cnt(int i) {
    for (int x : adj[i]) {
        cnt[i] += build_cnt(x);
    }
    return 1 + cnt[i];
}

/*
3 options
3 2 4
3 2 1
3 2 5

3 2 1
3 2 5
4 2 1
4 2 5

*/
void solve(int i, int carry) {
    // you start at the root
    cout << i << " " << cnt[i] << " " << carry << endl;
    int same_3 = 1ll;
    int same_2 = (cnt[i] + carry) * 3ll;
    int same_1 = cnt[i] * carry * 6ll;
    int total_except_i = cnt[i] + carry;  // includes parents

    for (int x : adj[i]) {
        // count number passing through i
        same_1 += (1 + cnt[x]) * (total_except_i - cnt[x] - 1) * 3ll;
    }
    // cout << same_1 << endl;
    // // add for not passing through i
    // for (int j = 0; j < adj[i].size(); j++) {
    //     for (int k = j + 1; k < adj[i].size(); k++) {
    //         for (int l = k + 1; l < adj[i].size(); l++) {
    //             same_1 += (1 + cnt[adj[i][j]]) * (1 + cnt[adj[i][k]]) * (1 + cnt[adj[i][l]]) * 6ll;
    //         }
    //         same_1 += (1 + cnt[adj[i][j]]) * (1 + cnt[adj[i][k]]) * (carry) * 6ll;
    //     }
    // }
    // cout << i << " " << left_cnt[i] << " " << right_cnt[i] << " " << carry << endl;
    // cout << same_1 << endl;

    ans[i] = same_3 + same_2 + same_1;

    for (int x : adj[i]) {
        solve(x, cnt[i] + carry - cnt[x]);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        unrooted_adj[u].push_back(v);
        unrooted_adj[v].push_back(u);
    }
    visited[1] = true;
    int root = 1;
    build_rooted(root);
    build_cnt(root);
    solve(root, 0);
    // build a tree and count the number of leafs on left and right

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
