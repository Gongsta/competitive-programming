#include <bits/stdc++.h>

using namespace std;

unordered_set<int> pho;
vector<int> adj[100001];
bool visited[100001];
unordered_set<int> not_included;
queue<int> leaves;
unordered_set<int> diameter_path;
unordered_set<int> dependent_node;
int N, M, n,m;

int final_node;
deque<int> dq;

int dfs(int curr, int prev, int length) {
    // Child node
    if (adj[curr].size() == 1 && prev == adj[curr][0]) {
        return length;
    }
    int max_len = length;
    for (auto x: adj[curr]) {
        if (x != prev) {
            dq.push_back(x);
            int curr_len = dfs(x, curr, length+1);
           if (curr_len > max_len) {
               max_len = curr_len;
               final_node = x;
           } else {
               dq.pop_back();
           }
        }
    }
    return max_len;

}

int diameter() {
    int a,b,c;
    for (int i=0; i<n;i++) {
        if (!not_included.count(i)) {
            a = i;
            break;
        }
    }
    // DFS on a;
    dfs(a, -1, 0);
    b = final_node;
    cout << "B" << b;
    dq.clear();
    // DFS on b;
    int final = dfs(b, -1, 0);
    c = final_node;
    
    cout << "dq path";
    while (!dq.empty()) {
        int a = dq.front(); dq.pop_front();
        diameter_path.insert(a);
        cout << a;
    }
    return final;
}

//Returns the minimum distance
int min_dfs(int curr, int prev, int dist) {
    if (pho.count(curr)) {
        return dist;
    }
    int final_dist = 1 << 30;
    int curr_dist;
    for (auto x: adj[curr]) {
        if (x != curr) {
            curr_dist = min_dfs(x, curr, dist+1);
            final_dist = min(curr_dist, final_dist);

        }
    }
    return final_dist;


}

int main() {
    /*
    Ideas: 
    1. (probs BAD) We can use Djikstra's Algorithm, but we would need to start at every Pho restaurant and find the max distance between 2 given pho restaurants.
        - And that doesn't work because that's not the question, you need to visit ALL Pho restaurants so its 
        a shortest path question but with EVERY node visit. Maybe Chapter 19?
        - Find the shortest hamiltonian path

    Maybe build a minimum spanning tree, and then Djikstras? NO
    
    2. Some tree algorithm for the CP Handbook... NO
    
    FINAL (After reading editorial):
    1. First start by removing all nodes that are irrelevant (will not be traversed on the final path, leaf nodes that are not pho restaurants)
    2. Find the diameter of the restaurant
    3. Find all the nodes that are closest to the diameter path, using DFS
    Final answer = diameter = 2* distances of pho restaurants

    */
   cin >> n >> m;
   M = m;
   N = n;
   int a, b;
   while (M--) {
       cin >> a;
       pho.insert(a);
   }
   N--;
   while (N--) {
       cin >> a >> b;
       adj[a].push_back(b);
       adj[b].push_back(a);
   }
   
   // 1. Remove the irrelevant leaf nodes, by first finding all the leaves, and then 
   // performing DFS, store in the not_included set
   for (int i=0;i<n;i++) {
       if (adj[i].size() == 1) {
           leaves.push(i);
       }
   }
    while (!leaves.empty()) {
        int x = leaves.front();leaves.pop();
        if (!pho.count(x) && (!dependent_node.count(x))) {
                not_included.insert(x);
                for (auto i: adj[x]) {
                    if (visited[i]) continue;
                    visited[i] = true;
                    leaves.push(i);
                }
        } else {
            for (auto i: adj[x]) {
                dependent_node.insert(i);
                if (visited[i]) continue;
                visited[i] = true;
                leaves.push(i);
            }
        }
    }

    
    // 2. Find diameter of the tree, by performing dfs twice
    int final_diameter = diameter();
    
    // 3.
    int val = 0;
    for (int i=0;i<n;i++) {
        if (!not_included.count(i) && !diameter_path.count(i)) {
            val += min_dfs(i, -1, 0);
        }
    }
    cout << final_diameter + 2 * val << endl;
    return 0;
}
