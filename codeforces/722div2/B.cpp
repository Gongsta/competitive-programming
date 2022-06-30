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
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        sort(a, a+n);

        bool positive = false;

        int count = 0;
        int curr_max = 0;
        bool duplicate = false;
        for (int i=0;i<n;i++) {
            if (a[i] > 0) {
                if (positive || duplicate) {
                    break;
                } else {
                    positive = true;
                }
            }
            if (i > 0 && a[i] == a[i-1]) {
                duplicate = true;
            }
            count++;
        }
        cout << count << endl;

    }

    return 0;
}
