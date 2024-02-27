#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b, l;
        cin >> a >> b >> l;
        int total = 0;
        int l_temp = l;
        int a_temp = 1;
        unordered_set<int> s;
        if (a == b) {
            int curr_count = 1;
            while (l % a == 0) {
                l /= a;
                curr_count += 1;
            }
            total = curr_count;
        } else {
            while (a_temp <= l) {
                int b_temp = 1;
                int curr_count = 0;
                while (l % (a_temp * b_temp) == 0 && (a_temp * b_temp) <= l && !s.count(a_temp * b_temp)) {
                    s.insert(a_temp * b_temp);
                    curr_count++;
                    b_temp *= b;
                }
                total += curr_count;
                a_temp *= a;
            }
        }
        cout << total << endl;
    }

    return 0;
}
