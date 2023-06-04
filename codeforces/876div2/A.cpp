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
        double k;
        cin >> n >> k;
        int a[n];
        double count = 0;
        for (double i=0;i<n;i++) {
            if (ceil((i+1)/k) > count) {
                count++;
                a[(int)i] = 1;
            } else {
                a[(int)i] = 0;
            }
        }
        if (a[n-1] == 0) {
            count++;
        }

        cout << count << endl;

    }

    return 0;
}
