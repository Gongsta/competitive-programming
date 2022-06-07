#include <bits/stdc++.h>

using namespace std;

unordered_set<int> s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,n;
    cin >> t;
    while (t--) {
        int count_zero = 0;
        cin >> n;
        int x;
        int temp = n;
        s.clear();
        bool duplicate =false;
        while (temp--) {
            cin >> x;
            if (x == 0) {
                count_zero++;
            }
            if (s.count(x)) {
                duplicate = true;
            } else {
                s.insert(x);
            }
        }
        if (count_zero > 0) {
            cout << n - count_zero << endl;
        } else {
            if (duplicate) {
                cout << n << endl;
            } else {
                cout << n + 1 << endl;
            }
        }
    }
    
    return 0;
}
