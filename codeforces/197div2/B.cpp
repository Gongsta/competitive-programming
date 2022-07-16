#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    ll a[m];
    for (int i=0;i<m;i++) {
        cin >> a[i];
    }
    ll total = 0;
    ll curr = 1;
    for (int i=0;i<m;i++) {
        if (a[i] < curr) {
            total += n - (curr) + 1;
            curr = 1;
        } 
        total += a[i] - curr;
        curr = a[i];
    }
    cout << total << endl;
    

    return 0;
}
