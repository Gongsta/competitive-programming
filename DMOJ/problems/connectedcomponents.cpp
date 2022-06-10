#include <bits/stdc++.h>

using namespace std;

int adj[1000][1000];
unordered_set<int> printed;
set<int> curr_set;
stack<int> s;
int N;
void find_neighbors(int curr) {
    for (int i=0; i<N;i++) {
        if (adj[curr][i] == 1) {
            if (printed.count(i)) continue;
            curr_set.insert(i);
            printed.insert(i);
            find_neighbors(i);
        }
    }
    printed.insert(curr);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> adj[i][j];
        }
    }

    for (int i=0;i<N;i++) {
        if (printed.count(i)) continue;
        curr_set.clear();
        curr_set.insert(i);
        for (int j=0;j<N;j++) {
            if (adj[i][j] == 1) {
                curr_set.insert(j);
                find_neighbors(j);
            }
        }
        printed.insert(i);
        for (auto x : curr_set) {
            cout << x+1 << " ";
        }
        cout << endl;
    }

    return 0;
}
