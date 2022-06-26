#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        string grid[n];
        for (int i=0;i<n;i++) {
            cin >> grid[i];
        }
        if (grid[0][0] == '1') {
            cout << -1 << endl;
        } else {
            vector<vector<int>> ops;
            for (int i=n-1;i>=0;i--) {
                for (int j=m-1;j>=0;j--) {
                    if (grid[i][j] == '1') {
                        vector<int> temp;
                        if (j == 0) {
                            temp.push_back(i);
                            temp.push_back(j+1);
                            temp.push_back(i+1);
                            temp.push_back(j+1);
                        } else {
                            temp.push_back(i+1);
                            temp.push_back(j);
                            temp.push_back(i+1);
                            temp.push_back(j+1);
                        }
                        ops.push_back(temp);
                    }

                }
            }
            cout << ops.size() << endl;
            for (vector<int>v : ops) {
                for (int i=0;i<4;i++) {
                    cout << v[i];
                    if (i == 3) {
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
