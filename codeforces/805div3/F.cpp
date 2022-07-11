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
        int b[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }

        for (int i=0;i<n;i++) {
            cin >> b[i];
        }
        sort(a, a+n,greater<int>());
        sort(b, b+n,greater<int>());
        bool 
        for (int i=0;i<n;i++) {
            int start= i;
            while (start < n) {
                while (a[start] < b[i]) {
                    a[start] *= 2;
                }
                if (a[start] > b[i]) {
                    start++;
                } else {
                    break;
                }
            }
        }
    }

    return 0;
}
