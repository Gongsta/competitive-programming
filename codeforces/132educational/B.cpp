#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    int n,m;
    cin >> n >> m;
    ll a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    ll forward[n];
    ll backward[n];
    for (int i=0;i<n;i++) {
        if (i == 0) {
            forward[i] = 0;
        } else {
            if (a[i] - a[i-1] < 0)  {
                forward[i] = abs(a[i]-a[i-1]);
            } else {
                forward[i] = 0;
            }
        }
    }
    for (int i=n-1;i>=0;i--) {
        if (i == n-1) {
            backward[i] = 0;
        } else {
            if (a[i] - a[i+1] < 0)  {
                backward[i] = abs(a[i]-a[i+1]);
            } else {
                backward[i] = 0;
            }
        }
    }

    for (int i=1;i<n;i++) {
        forward[i] += forward[i-1];
    }     
    for (int i=n-2;i>=0;i--) {
        backward[i] += backward[i+1];
    }     
    while (m--) {
        int s,t;
        cin >> s >> t;
        s--;
        t--;
        if (s < t) {
            cout << forward[t] - forward[s] << endl;
        } else {
            swap(s,t);
            cout << backward[s] - backward[t] << endl;
        }
    }



    return 0;
}
