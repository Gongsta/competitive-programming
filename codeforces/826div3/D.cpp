#include <iostream>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        int p_min[2*m];
        int p_max[2*m];
        int p_size[2*m];
        int p[m];
        for (int i=0;i<m;i++) {

            cin >> p[i];
            p_min[m+i] = p[i];
            p_max[m+i] = p_min[m+i];
            p_size[m+i] = 1;
        }
        int total = 0;
        for (int i=m-1;i>=1; i--) {
            p_min[i] = min(p_min[2*i], p_min[2*i + 1]);
            p_max[i] = max(p_max[2*i], p_max[2*i + 1]);
            p_size[i] = p_size[2*i] + p_size[2*i + 1];
            if (p_max[i] - p_min[i] >= p_size[i]) {
                // cout << i << " "  << p_max[i] << " " << p_min[i] << " " << p_min[i] << endl;
                total = -1;
                break;
            }
        }
        if (total != -1) {
            total = 0;
            for (int k=1;k<m;k*=2) {
                int i = 0;
                while (i < m) {
                    if (p[i] > p[i+k]) {
                        swap(p[i], p[i+k]);
                        total++;
                    }
                    i += 2*k;
                }
            }
        }
        if (m == 1) {
            cout << 0 << endl;

        } else {
            cout << total << endl;
        }

    }

    return 0;
}
