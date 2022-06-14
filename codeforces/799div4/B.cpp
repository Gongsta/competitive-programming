#include <bits/stdc++.h>

using namespace std;

map<int, int> m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        m.clear();
        int x;
        while (n--) {
            cin >> x;
            if (m.count(x)) {
                m[x]++;
            } else {
                m[x] = 1;
            }
        }
        int count = 0;
        int duplicate_count = 0;
        for (auto x: m) {
            if (x.second >= 2 && x.second % 2 == 0) {
                duplicate_count++;
            }
        }
        for (auto x: m) {
            count += (x.second % 2);
        }
        if (duplicate_count % 2 == 0) {
            count+=duplicate_count;
        }
        else if (duplicate_count > 2) {
            count += duplicate_count - 1;
        }
        
        cout << count << endl;

    }

    return 0;
}
