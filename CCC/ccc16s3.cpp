#include <bits/stdc++.h>

using namespace std;

unordered_set<int> pho;
vector<int> adj[100001];
unordered_set<int> not_included;
set<int> leaves;
unordered_set<int> diameter_path;
int N, M, n,m;

void dfs_leaf_search(int curr, int prev) {
    if (pho.count(curr) != 0 || not_included.count(curr)) {
        return;
    } else {
        not_included.insert(curr);
        for (auto x: adj[curr]) {
            if (x != prev) {
                dfs_leaf_search(x, curr);
            }
        }
    }
}

int final_node
int dfs(int curr, int prev) {
    if (adj[curr].size() == 1 && prev == adj[curr][0]) {
        return length;
    }
    for (auto x: adj[curr]) {
        if (x != prev) {
            dfs(x, curr);
        }
    }

}

void diameter() {
    int a,b,c;
    for (int i=0; i<n;i++) {
        if (!not_included.count(i)) {
            a = i;
            break;
        }
    }
    // Dfs on a;
    b = dfs(a, -1);
    c = dfs(b, -1);
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
           leaves.insert(i);
       }
   }
   
   for (auto leaf: leaves) {
       dfs_leaf_search(leaf, -1);

   }
    
    // 2. Find diameter of the tree, by performing dfs twice
    return 0;
}
