#include <bits/stdc++.h>

using namespace std;

int start[200001];
int f[200001];
int duration[200001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> start[i];

        }
        for (int i=0;i<n;i++) {
            cin >> f[i];
        }
        
        
        duration[0] = f[0] - start[0];

        for (int i=1;i<n;i++) {
            if (start[i] >= f[i-1]) {
                duration[i] = f[i] - start[i];
            } else {
                duration[i] = f[i] - f[i-1];
            }
        }
        //Print answer
        for (int i=0;i<n;i++) {
            cout << duration[i];
            if (i != n-1) {
                cout << " ";
            } else {
                cout << endl;

            }
        }
    }

    return 0;
}
