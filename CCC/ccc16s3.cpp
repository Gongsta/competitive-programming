#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
bitset<100001> visited;
bitset<100001> pho;
bitset<100001> not_included;
bitset<100001> diameter_path;
queue<int> leaves;
unordered_set<int> dependent_node;
int N, M, n,m;

int final_node;
// deque<int> dq;

int pho_leaf_node(int i){
    if (!pho[i]) {
        return -2;
    }
    int total = 0;
    int prev = -1;
    for (auto x: adj[i]) {
        if (!not_included[x]) {
            total++;
            prev = x;
        }
    }
    if (total == 1) {
        return prev;
    } else {
        return -2;
    }
}
int dfs(int curr, int prev, int length) {
    // Child node
    if (pho_leaf_node(curr) == prev) {
        return length;
    }
    int max_len = length;
    for (auto x: adj[curr]) {
        if (x != prev && !not_included[x]) {
            diameter_path[x] = 1;
            int curr_len = dfs(x, curr, length+1);
           if (curr_len > max_len) {
               max_len = curr_len;
               if (pho_leaf_node(x) != -2) {
                //    cout << "pho leaf node" << x;
                    final_node = x;
               }
           } else {
               diameter_path[x] = 0;
           }
        }
    }
    return max_len;

}

int diameter() {
    int a,b;
    for (int i=0; i<n;i++) {
        // Set to the first node that is included in the final search
        if (!not_included[i]) {
            a = i;
            break;
        }
    }
    // DFS on a;
    dfs(a, -1, 0);
    b = final_node;
    diameter_path.reset();
    // DFS on b;
    diameter_path[b] = 1;
    int final = dfs(b, -1, 0);
    
    // while (!dq.empty()) {
    //     int a = dq.front(); dq.pop_front();
    //     diameter_path[a] = 1;
    // }
    return final;
}

//Returns the minimum distance
int min_dfs(int curr, int prev, int dist) {
    if (diameter_path[curr]) {
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
       pho[a] = 1;
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
        if (!pho[x] && (!dependent_node.count(x))) {
                not_included[x] = 1;
                for (auto i: adj[x]) {
                    if (visited[i]) continue;
                    visited[i] = 1;
                    leaves.push(i);
                }
        } else {
            for (auto i: adj[x]) {
                dependent_node.insert(i);
                if (visited[i]) continue;
                visited[i] = 1;
                leaves.push(i);
            }
        }
    }
    dependent_node.clear();
    
    // 2. Find diameter of the tree, by performing dfs twice
    int final_diameter = diameter();
    
    // 3.
    int val = 0;
    for (int i=0;i<n;i++) {
        if (!not_included[i] && !diameter_path[i]) {
            val += min_dfs(i, -1, 0);
        }
    }
    cout << final_diameter + 2 * val << endl;
    return 0;
}