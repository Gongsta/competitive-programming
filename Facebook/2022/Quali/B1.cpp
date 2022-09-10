#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    for (int t=1;t<=tt;t++) {
        int R,C;
        cin >> R >> C;
        string grid[R];
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
        }         
        cout << "Case #" << t << ": " << works << endl;
        if (works == "Possible") {
            if (R == 1 || C == 1) {
                for (int i=0;i<R;i++) {
                    for (int j=0;j<C;j++) {
                        cout << '.';
                    }
                    cout << endl;
                }
            } else {
                for (int i=0;i<R;i++) {
                    for (int j=0;j<C;j++) {
                        cout << '^';
                    }
                    cout << endl;
                }
            }

        }
    }

    return 0;
}
