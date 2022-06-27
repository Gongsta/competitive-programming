#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll C(ll n, ll k) {
    double res = 1;
    for (ll i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (ll)(res + 0.01);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    // Finding the minimum
    ll total = 0;
    ll curr_sum = 0;
    int increment = ceil(double(n) / double(m));
    for (int i=0;i<m;i++) {
        while (curr_sum + (m-i) * (increment - 1) >= n) {
            increment--;
        }
        if (increment == 1) {
            break;
        }
        total += C(increment,2);
        curr_sum += increment;

    }
    

    cout << total << " ";
    
    // Finding maximum
    ll largest = n - (m-1);
    cout << C(largest, 2) << endl;

    return 0;
}
