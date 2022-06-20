#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int table[40][40];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        int small_i,small_j,max_val;
        int h, w;
        max_val = 1 << 30;
        max_val = - max_val;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                cin >> table[i][j];
                if (table[i][j] > max_val) {
                    small_i = i;
                    h = max(n-i, i+1);
                    small_j = j;
                    w = max(m-j, j+1);
                    max_val = table[i][j];
                } else if (table[i][j] == max_val) {
                    int new_h = max(n-i, i+1);
                    int new_w = max(m-j, j+1);
                    if (new_h * new_w < h * w) {
                        small_i = i;
                        small_j = j;
                        h = new_h;
                        w = new_w;
                    }
                    
                }
            }
hh
    }

    return 0;
}
