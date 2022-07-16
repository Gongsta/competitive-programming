#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    ll sum_a = 0;
    ll sum_g = 0;
    cin >> n;
    string seq;
    while (n--) {
        int a,g;
        cin >> a >> g;
        if (sum_a + a - sum_g > 500) {
            sum_g += g;
            seq += "G";
        } else {
            sum_a += a;
            seq += "A";
        }
    }
    if (abs(sum_a-sum_g) > 500) {
        cout << -1 << endl;
    } else {
        cout << seq << endl;

    }

    return 0;
}
