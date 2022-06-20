#include <bits/stdc++.h>

using namespace std;

vector<int> final;
int n;
int c[100001];
vector<int> adj[100001];

void dfs(int curr, int prev) {
    if (c[curr] == 1) {
        bool works = true;
        for (int i: adj[curr]) {
            if (c[i]  != 1) {
                works = false;
            }
        }
        if (works) {
            final.push_back(curr);
        }
    }

    for (int i: adj[curr]) {
        if (i != prev) {
            dfs(i, curr);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> n;
    int root;
    for (int i=1;i<=n;i++) {
        int p;
        cin >> p;
        cin >> c[i];
        if (p == -1) {
            root = i;
        } else {
            adj[p].push_back(i);
        }
    }
    dfs(root, -1);
    if (final.empty()) {
        cout << -1 << endl;
    } else {
        sort(final.begin(), final.end());
        for (int i=0;i<final.size();i++) {
            cout << final[i];
            if (i != final.size() - 1) {
                cout << " ";
            } else {
                cout << endl;
            }

        }
    }

    return 0;
}
