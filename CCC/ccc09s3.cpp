#include <bits/stdc++.h>

using namespace std;

// A very standard graph problem

set<int> adj[51];
map<int, int> friends;
unordered_set<int> fof;
unordered_set<int> visited;
queue<int> q;
int dist[51];

void make_friends(int x, int y) {
    if (!adj[x].count(y)) {
        friends[x] += 1;
        adj[x].insert(y);
    }
    if (!adj[y].count(x)) {
        friends[y] += 1;
        adj[y].insert(x);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char i;
    int x,y;
    for (int i=1;i<=50;i++) {
        friends[i] = 0;
    }
    
    make_friends(1,6);
    make_friends(2,6);
    make_friends(3,6);
    make_friends(4,6);
    make_friends(5,6);
    make_friends(7,6);
    make_friends(3,4);
    make_friends(3,15);
    make_friends(3,5);
    make_friends(4,5);
    make_friends(15,13);
    make_friends(13,14);
    make_friends(13,12);
    make_friends(12,11);
    make_friends(11,10);
    make_friends(12,9);
    make_friends(9,10);
    make_friends(8,9);
    make_friends(7,8);
    make_friends(16,17);
    make_friends(17,18);
    make_friends(18,16);
    while (true) {
        cin >> i;
        if (i == 'q') {
            break;
        } else if (i == 'i') {
            cin >> x >> y;
            make_friends(x,y);

        } else if (i == 'd') {
            cin >> x >> y;
            set<int>::iterator it = find(adj[x].begin(), adj[x].end(), y);
            adj[x].erase(it);
            it = find(adj[y].begin(), adj[y].end(), x);
            adj[y].erase(it);
            friends[x]--;
            friends[y]--;
        } else if (i =='n') {
            cin >> x;
            cout << friends[x] << endl;
        } else if (i == 'f') {
            cin >> x;
            // BFS
            fof.clear();
            visited.clear();
            for (auto f: adj[x]) {
                q.push(f);
                visited.insert(f);
            }
            visited.insert(x);
            while (!q.empty()) {
                int val = q.front(); q.pop();
                for (auto f: adj[val]) {
                    if (!visited.count(f)) {
                        fof.insert(f);
                        visited.insert(f);
                    }
                }
            }
            
            cout << fof.size() << endl;
        } else if (i == 's') {
            // BFS
            visited.clear();
            cin >> x >> y;
            // BFS
            q.push(x);
            visited.insert(x);
            dist[x] = 0;
            dist[y] = 0; // Reset the target node
            while (!q.empty()) {
                int val = q.front(); q.pop();
                for (auto f: adj[val]) {
                    if (!visited.count(f)) {
                        visited.insert(f);
                        dist[f] = dist[val] + 1;
                        q.push(f);
                    }
                }
            }
            if (dist[y] == 0 && x != y) {
                cout << "Not connected" << endl;
            } else {
                cout << dist[y] << endl;
            }
        }


    }
    return 0;
}
