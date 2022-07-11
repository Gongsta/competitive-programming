#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll start = 1;
        ll copies = 1;
        ll hours = 0;
        while (copies < k) {
            start += copies;
            copies *= 2;
            hours++;
        }
        hours += ceil((long double)(n - start)/(long double) k);
        cout << hours << endl;

    }

    return 0;
}
