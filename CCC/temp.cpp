#include <bits/stdc++.h>

using namespace std;

// Running into memory issues, so I will remove the diameter path way
vector<int> adj[100001];
bitset<100001> visited;
unordered_set<int> not_included;
queue<int> leaves;
unordered_set<int> pho;
unordered_set<int> dependent_node;
int N, M, n,m;

int start_node;
int temp_final_node;
int final_node;

int pho_leaf_node(int i){
	if (!pho.count(i)) {
		return -2;
	}
    int total = 0;
    int prev = -1;
    for (auto x: adj[i]) {
        if (!not_included.count(x)) {
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
        temp_final_node = curr;
        return length;
    }
    int max_len = length;
    for (auto x: adj[curr]) {
        if (x != prev && !not_included.count(x)) {
            int curr_len = dfs(x, curr, length+1);
           if (curr_len > max_len) {
               max_len = curr_len;
               // The update here is bad, because it is called too often
			   if (pho_leaf_node(x) != -2) {
            		final_node = temp_final_node;
			   }
            //    cout << "final_node" << final_node;
           } 
        }
    }
    return max_len;

}

int diameter() {
    for (int i=0; i<n;i++) {
        // Set to the first node that is included in the final search
        if (!not_included.count(i)) {
            start_node = i;
            break;
        }
    }
    // DFS on a;
    dfs(start_node, -1, 0);
    int b = final_node;
    start_node = final_node;
    int final = dfs(b, -1, 0);
    
    return final;
}

//Returns the minimum distance
int min_dfs(int curr, int prev, int dist) {
    if (adj[curr].size() >= 3 && prev != -1) {
        return dist;
    }
    int final_dist = 1 << 30;
    int curr_dist;
    for (auto x: adj[curr]) {
        if (x != prev && !not_included.count(x)) {
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
        if (pho_leaf_node(i) != -2 && !not_included.count(i) && i!=start_node && i!=final_node) {
            val += min_dfs(i, -1, 0);
        }
    }
    cout << final_diameter + 2 * val << endl;
    return 0;
}