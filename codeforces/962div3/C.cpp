#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string a;
        string b;
        cin >> a >> b;
        vector<int> alphabet_a[26];
        vector<int> alphabet_b[26];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                int latest_a = 0;
                int latest_b = 0;
                if (!alphabet_a[j].empty()) {
                    latest_a = alphabet_a[j].back();
                }
                if (!alphabet_b[j].empty()) {
                    latest_b = alphabet_b[j].back();
                }

                if (a[i] - 'a' == j) {
                    alphabet_a[j].push_back(latest_a + 1);
                } else {
                    alphabet_a[j].push_back(latest_a);
                }
                if (b[i] - 'a' == j) {
                    alphabet_b[j].push_back(latest_b + 1);
                } else {
                    alphabet_b[j].push_back(latest_b);
                }
            }
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int common = 0;
            for (int i = 0; i < 26; i++) {
                if (l == 0) {
                    common += min(alphabet_a[i][r], alphabet_b[i][r]);
                } else {
                    common += min(alphabet_a[i][r] - alphabet_a[i][l - 1], alphabet_b[i][r] - alphabet_b[i][l - 1]);
                }
            }
            cout << (r - l + 1) - common << endl;
        }
    }

    return 0;
}
