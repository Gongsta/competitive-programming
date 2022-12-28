#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll sum = n;
        if (n %2 == 0) {
            sum += n;
        } else {
            sum += n-1;
        }
        if (n % 3 == 0) {
            sum += n / 3 * 2;
        } else if (n % 3 == 1) {
            sum += (n-1) / 3 * 2;
        } else {
            sum += (n-2) / 3 * 2;
        }

        cout << sum << endl;

    }

    return 0;
}
