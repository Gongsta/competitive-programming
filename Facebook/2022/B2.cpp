#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

string s[3000];
int count_potential_trees(int i, int j, int R, int C) {
    int ans = 0;
    if (i > 0 && s[i-1][j] != '#') {
        ans++;
    }
    if (i < R-1 && s[i+1][j] != '#') {
        ans++;
    }
    if (j > 0 && s[i][j-1] != '#') {
        ans++;
    }
    if (j < C-1 && s[i][j+1] != '#') {
        ans++;
    }
    return ans;
}
int count_trees(int i, int j, int R, int C, vector<string> &ans) {
    int tot = 0;
    if (i > 0 && ans[i-1][j] == '^') {
        tot++;
    }
    if (i < R-1 && ans[i+1][j] == '^') {
        tot++;
    }
    if (j > 0 && ans[i][j-1] == '^') {
        tot++;
    }
    if (j < C-1 && ans[i][j+1] == '^') {
        tot++;
    }
    return tot;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    for (int t=1;t<=tt;t++) {
        int R,C;
        cin >> R >> C;
        vector<string> ans;
        for (int i=0;i<R;i++) {
            cin >> s[i];
            ans.push_back(s[i]);
        }
        for (int i=0;i<R;i++) {
            for (int j=0;j<C;j++) {
                if (count_potential_trees(i, j, R, C) >= 2 && ans[i][j] != '#') {
                    ans[i][j] = '^';
                }            
            }
        }
        for (int i=0;i<R;i++) {
            for (int j=0;j<C;j++) {
                if (count_trees(i, j, R, C, ans) < 2 && ans[i][j] == '^' && s[i][j] == '.') {
                    ans[i][j] = '.';
                }            
            }
        }
        bool works = true;
        for (int i=0;i<R;i++) {
            for (int j=0;j<C;j++) {
                if (ans[i][j] == '^' && count_trees(i, j, R, C, ans) < 2) {
                    works = false;
                    break;
                }            
            }
        }
        if (works) {
            cout << "Case #" << t << ": " << "Possible" << endl;
            for (int i=0;i<R;i++) {
                cout << ans[i] << endl;
            }

        } else {
            cout << "Case #" << t << ": " << "Impossible" << endl;

        }
    }

    return 0;
}
