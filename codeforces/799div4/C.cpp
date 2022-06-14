#include <bits/stdc++.h>

using namespace std;

char board[8][8];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        for (int i=0;i<8;i++) {
            for (int j=0;j<8;j++) {
                cin >> board[i][j];
            }
        }
        int count[8] = {0};
        for (int i=0;i<8;i++) {
            int total = 0;
            for (int j=0;j<8;j++) {
                if (board[i][j] == '#') {
                    total++;
                }
            }
            count[i] = total;
        }
        for (int i=1;i<7;i++) {
            bool found = false;
            if (count[i] == 1 && count[i-1] == 2 && count[i+1] == 2) { // find the bishop
                for (int j=0;j<8;j++) {
                    if (board[i][j] == '#') {
                        cout << i + 1 << " " << j + 1 << endl;
                        found = true;
                        break;
                    }
                }
            }
            if (found) {
                break;
            }
        }
    }

    return 0;
}
