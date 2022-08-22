#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


ll sum_string(string n) {
    ll total = 0;
    for (auto x: n) {
        total += x - '0';
    }
    return total;

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        ll n_int = stoll(n);
        while (gcd(n_int, sum_string(to_string(n_int))) == 1ll) {
            n_int++;
        }
        cout << n_int << endl;

    }

    return 0;
}
