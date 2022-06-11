#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n;
        int max_a = 0;
        int max_b = 0;
        int a,b;
        while (n--) {
            cin >> a;
            max_a = max(a, max_a);
        }
        cin >> m;
        while (m--) {
            cin >> b;
            max_b = max(b, max_b);
        }
        if (max_a > max_b) {
            cout << "Alice" << endl;
            cout << "Alice" << endl;
        } else if (max_b > max_a) {
            cout << "Bob" << endl;
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
            cout << "Bob" << endl;
        }
        
    }

    return 0;
}
