#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool check_and_update_surroundings(vector<string> &grid, int i, int j) {
    int total = 0;
    int curr_trees = 0;
    if (i>0 && grid[i-1][j] != '#') {
        if (grid[i-1][j] == '^') {
            curr_trees++;
        }
        total++;
    }
    if (j>0 && grid[i][j-1] != '#') {
        if (grid[i][j-1] == '^') {
            curr_trees++;
        }
        total++;
    }
    if (i<grid[0].length()-1 && grid[i+1][j] != '#') {
        if (grid[i+1][j] == '^') {
            curr_trees++;
        }
        total++;
    }
    if (j<grid.size()-1 && grid[i][j+1] != '#') {
        if (grid[i][j+1] == '^') {
            curr_trees++;
        }
        total++;
    }

    if (total < 2) {
        return false;
    } else {
        if (curr_trees >= 2) {
            return true;
        } else {
            if (i>0 && grid[i-1][j] != '#') {
                if (grid[i-1][j] != '^') {
                    curr_trees++;
                }
                total++;
            }
            if (j>0 && grid[i][j-1] != '#') {
                if (grid[i][j-1] == '^') {
                    curr_trees++;
                }
                total++;
            }
            if (i<grid[0].length()-1 && grid[i+1][j] != '#') {
                if (grid[i+1][j] == '^') {
                    curr_trees++;
                }
                total++;
            }
            if (j<grid.size()-1 && grid[i][j+1] != '#') {
                if (grid[i][j+1] == '^') {
                    curr_trees++;
                }
                total++;
            }   
        }

    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    for (int t=1;t<=tt;t++) {
        int R,C;
        cin >> R >> C;
        vector<string> grid(R);
        for (int i=0;i<R;i++) {
            cin >> grid[i];
        }
        string works = "Possible";
        // Special Cases, 1 Row or 1 col
        if (R == 1 || C == 1) {
            for (int i=0;i<R;i++) {
                for (int j=0;j<C;j++) {
                    if (grid[i][j] == '^') {
                        works = "Impossible";
                        break;
                    }
                }
            }
        } else {
            for (int i=0;i<R;i++) {
                for (int j=0;j<C;j++) {
                    if (grid[i][j] == '^') {
                        works = "Impossible";
                        break;
                    }
                }
            }

        }
        cout << "Case #" << t << ": " << works << endl;
        if (works == "Possible") {
            for (int i=0;i<R;i++) {
                for (int j=0;j<C;j++) {
                    cout << grid[i][j];
                }
                cout << endl;
            }

        }
    }

    return 0;
}
