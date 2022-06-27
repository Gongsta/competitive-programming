#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int total = 0;
    for (int i=0;i<m;i++) {
        if (a[i]>=0) {
            break;
        }
        total += abs(a[i]);
    }
    cout << total << endl;

    return 0;
}
