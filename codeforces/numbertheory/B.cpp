#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << n / 2 << " ";
        cout << n / 2 + (n % 2) << endl;


    }

    return 0;
}
