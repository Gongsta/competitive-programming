#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { // Euclidean Algorithm
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << n / 2 << endl;

    }

    return 0;
}
