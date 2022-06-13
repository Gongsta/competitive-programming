/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

vector<int> adj[4001];
string s;
int total = 0;

void dfs(int x) {
    if (s[x] == 'W') {
        total++;
    } else {
        total--;
    }
    for (auto i: adj[x]) {
        dfs(i);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x;
        for (int i=1;i<=n;i++) {
            adj[i].clear();
        }
        for (int i=2;i<=n;i++) {
            cin >> x;
            adj[x].push_back(i);
        }
        cin >> s;
        int count = 0;
        for (int i=1;i<=n;i++) {
            total = 0;
            dfs(i);
            if (total == 0) {
                count++;
            }
        }
        cout << count << endl;
        
    }

    return 0;
}
