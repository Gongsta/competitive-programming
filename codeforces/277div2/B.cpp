#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    int A[n][m];
    int B[n][m];
    memset(A, 0, sizeof(A));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> B[i][j];
        }
    }
    bool works = true;
    bool has_one = false;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            // Check that at least one of the rows or columns is good
            if (B[i][j] == 1) {
                has_one = true;
                bool valid_row = true;
                for (int jj=0;jj<m;jj++) {
                    if (B[i][jj]!= 1) {
                        valid_row = false;
                        break;
                    }
                }
                bool valid_col = true;
                for (int ii=0;ii<n;ii++) {
                    if (B[ii][j] != 1) {
                        valid_col = false;
                        break;
                    }
                }
                if (!(valid_row || valid_col)) {
                    works = false;
                    break;
                }
                if (valid_row && valid_col) {
                    A[i][j] = 1;
                }
            }
        }
        if (!works) {
            break;
        }
    }
    if (has_one) {
        bool A_has_one = false;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if(A[i][j] == 1)  {
                    A_has_one = true;
                    break;
                }
            }
        }
        if (!A_has_one) {
            works = false;
        }

    }
    if (works) {
        cout << "YES" << endl;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                cout << A[i][j];
                if (j == m-1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }
    } else {
        cout << "NO" << endl;
    }


    return 0;
}
