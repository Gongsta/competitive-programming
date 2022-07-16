#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n,k,x;
    cin >> n >> k >> x;
    ll a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    vector<ll> dist;
    int groups = 1;
    for (int i=1;i<n;i++) {
        if (a[i] - a[i-1] > x) {
            dist.push_back(a[i] - a[i-1]);
            groups++;
        }
    }
    sort(dist.begin(),dist.end());
    for (int i=0;i<dist.size();i++) {
        if (k <= 0) {
            break;
        }

        k -= (ceil((long double)(dist[i]) / (long double)(x)) - 1);

        if (k >= 0) {
            groups--;
        } else {
            break;
        }
    }
    cout << groups << endl;

    return 0;
}
