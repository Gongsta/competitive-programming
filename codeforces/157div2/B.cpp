#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int grid[3][3];
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            cin >> grid[i][j];
        }
    }
    for (int i=0;;i++) {
        grid[0][0] = i;
        grid[1][1]= grid[0][2] + grid[0][1] + grid[0][0] - grid[1][0] - grid[1][2];
        grid[2][2]= grid[0][2] + grid[0][1] + grid[0][0] - grid[2][0] - grid[2][1];
        
        if (grid[0][0] + grid[1][1] + grid[2][2] == grid[0][0] + grid[1][0] + grid[2][0]) {
            break;
        }
    }
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            cout << grid[i][j];
            if (j == 2) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }


    return 0;
}
