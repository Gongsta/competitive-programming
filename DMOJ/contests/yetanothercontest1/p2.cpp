#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> adj[200001];

// Okay, this solution doesn't work, but my implementation doesn't work as well...
//https://dmoj.ca/problem/yac1p2

// TOO SLOW
unordered_map<int, set<int>> m; // Stores all trajectories to avoid double counting
int solve(int start, int prev, int i, int count, int numSols) {
    if (s[i-1] == 'B') {
        count += 1;
    }
    if (count >= 3 && !(m[start].count(i))) {
        m[i].insert(start);
        numSols += 1;
    }
    for (int j: adj[i]) {
        if (j != prev) {
            numSols = solve(start, i, j, count, numSols);
        }
    }
    return numSols;

}

// Because it is a tree, we can guarantee that there is only one path between any 2 nodes. 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;

    cin >> N;
    cin >> s;
    int Q = N;
    Q -= 1;
    int a, b;
    while (Q--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int total = 0;
    for (int i=1; i<=N; i++) {
        total += solve(i,0,i,0,0);
    }
    cout << total << endl;
    
    return 0;
}
