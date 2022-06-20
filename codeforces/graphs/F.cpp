#include <bits/stdc++.h>

using namespace std;

vector<int> adj[300001];
int indegrees[300001];
int dp[300001][27];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int x, y;
    for (int i=0;i<m;i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        indegrees[y]++;
    }
    queue<int> q;
    for (int i=1;i<=n;i++) {
        if (indegrees[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topsort;
    while (!q.empty()) {
        x = q.front(); q.pop();
        topsort.push_back(x);
        for (int i: adj[x]) {
            indegrees[i]--;
            if (indegrees[i] == 0) {
                q.push(i);
                
            }
        }
    }
    if (topsort.size() != n) {
        cout << -1 << endl;
    } else {
        int max_val = 0;
        for (char a='a';a<='z';a++) {
            for (int x: topsort) {
                if (s[x-1] == a) {
                    dp[x][a-'a']++;
                }
                for (auto i: adj[x]) {
                    dp[i][a-'a'] = max(dp[i][a-'a'], dp[x][a-'a']);
                }
                max_val = max(dp[x][a-'a'], max_val);
            }

        }
        cout << max_val << endl;

    }

    return 0;
}
