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
        memset(a, -1, sizeof(a));
        set<int> s;
        for (int i=n-1;i>=0;i--) {
            if (a[i] != -1) continue;
            for (int k=sqrt(2*(n-1)) + 1;k>=0;k--) {
                if (!s.count(k*k - i) && k*k-i>=0 && k*k-i<n) {
                    s.insert(k*k-i);
                    s.insert(i);
                    a[i]=  k*k - i;
                    a[k*k-i] = i;
                    break;
                }
            }
            
        }
        for (int i=0;i<n;i++) {
            cout << a[i];
            if (i == n-1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }

    }

    return 0;
}
