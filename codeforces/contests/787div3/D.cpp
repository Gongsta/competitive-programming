#include <bits/stdc++.h>

using namespace std;

vector<int> adj[20001];
int visited[200001];
deque<int> dq;
deque<int> q;

// Lessons: Be very careful with declaring the global variables, 
// as you don't expect them to change sometimes

bool use_queue;
int dfs(int curr, int prev, int length) {
    if (adj[curr].size() == 0) { // Leaf node
        return length;
    }
    int max_length = length;
    for (auto x: adj[curr]) {
        if (x != prev) {
            // cout << "X" << x << endl;
            dq.push_back(x);
            if (use_queue) {
                q.push_back(x);
            }
            int curr_len = dfs(x, curr, length+1);
            if (curr_len > max_length) {
                max_length = curr_len;
                if (use_queue) {
                    q.pop_back();
                }
            } else {
                dq.pop_back(); // current path
            }
        }
    }
    return max_length;

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int root_node;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x;
        for (int i=1;i<=n;i++) {
            cin >> x;
            if (x == i) {
                root_node = x;
            } else {
                adj[x].push_back(i);
            }
        }
        q.push_back(root_node);
        dq.push_back(root_node);
        use_queue = true;
        while (!q.empty()) {
            int x = q.front(); q.pop_front();
            int len = dfs(x,-1,0);
            use_queue = false;
            if (len == 0) {
                cout << 1 << endl;
                cout << x << endl;
            } else {
                cout << dq.size() << endl;
                while (!dq.empty()) {
                    cout << dq.front();
                    dq.pop_front();
                    if (dq.empty()) {
                        cout << endl;
                    } else {
                        cout << " ";
                    }
                }
            }
        }
    }

    return 0;
}
