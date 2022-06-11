#include <bits/stdc++.h>

using namespace std;
unordered_map<int, int> m;
vector<pair<int, int> > adj[1001];

vector<int> path;
bitset<1001> visited;
bool dfs(int curr, int prev, int threshold) {
    if (curr == B)
    for (auto x: adj[curr]) {
        if (x.first >= threshold) {
            if (x.second != prev) {
                dfs(x, curr, threshold);
            }

        }
    }


}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int threshold = 0;
    int N, M, F, A, B;
    cin >> M >> N;
    for (int i=1;i<=M;i++) {
        cin >> F;
        m[i] = F;
        threshold += F;
    }

    for (int i=1;i<=N;i++) {
        cin >> A >> B;
        adj[A].push_back({m[i], B});
        adj[B].push_back({0, A});

    }
    

    return 0;
}
