#include <bits/stdc++.h>

using namespace std;

// Strategy: Always delete the subtree with the most leaves, or choose the leaves with the least amount of substrees. I am failing to realize the difficulty of the problem

vector<int> adj[300001];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int N = n - 1;
        int u,v;
        while (N--) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        queue<int> q;
        q.push(1);
        
        int dist = 0;
        int curr_count = 0;
        int num_children = 1;
        int new_num_children = 0; // Keep track of number of children at each layer
        
        while (!q.empty()) {
            int i = q.front(); q.pop();
            if (adj[i].size() <= 1) {
                break;
            }
            curr_count++;
            new_num_children += adj[i].size();
            if (curr_count == num_children) {
                dist++;
                num_children = new_num_children;
                new_num_children = 0;
                curr_count = 0;
            }
            
            for (auto x: adj[i]) {
                q.push(x);
            }
        }
        cout << "Dist" << dist << endl;
        cout << n - 2 * dist - 1 << endl;
        
    }

    return 0;
}
