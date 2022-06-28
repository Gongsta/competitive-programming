#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int h[n];
        for (int i=0;i<n;i++) {
            cin >> h[i];
        }
        sort(h, h+n);
        int min_diff = 2e9;
        int min_i = -1;
        for (int i=1;i<n;i++) {
            if (h[i]-h[i-1] < min_diff) {
                min_i = i-1;
                min_diff = h[i] - h[i-1];
            }

        }
        for (int i=min_i;i<n;i++)  {
            if (i == min_i + 1) continue;
            cout << h[i] << " ";
        }
        for (int i=0;i<min_i;i++)  {
            if (i == min_i + 1) continue;
            cout << h[i] << " ";
        }
            cout << h[min_i + 1] << endl;
    }

    return 0;
}
