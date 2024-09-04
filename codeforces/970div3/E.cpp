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

vector<int> even_prefix[26];
vector<int> odd_prefix[26];

void insert(vector<int>& v, int val) {
    if (v.empty()) {
        v.push_back(val);
    } else {
        v.push_back(v.back() + val);
    }
}

int prefix_sum(vector<int>& prefix, int l, int r) {
    if (r < 0 || l >= prefix.size()) {
        return 0;
    } else if (l == 0) {
        return prefix[r];
    }
    return prefix[r] - prefix[l - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int c = 0; c < 26; c++) {
            even_prefix[c].clear();
            odd_prefix[c].clear();
        }
        for (int i = 0; i < n; i++) {
            for (int c = 0; c < 26; c++) {
                // cout << "before" << s[i] << " " << c << " " << i << " " << even_prefix[c][i] << endl;
                if (s[i] == ('a' + c)) {
                    if (i % 2 == 0) {
                        insert(even_prefix[c], 1);
                        insert(odd_prefix[c], 0);
                    } else {
                        insert(even_prefix[c], 0);
                        insert(odd_prefix[c], 1);
                    }
                } else {
                    insert(even_prefix[c], 0);
                    insert(odd_prefix[c], 0);
                }
                // cout << s[i] << " " << c << " " << i << " " << even_prefix[c][i] << endl;
            }
        }
        if (n % 2 == 0) {  // Cannot delete
            int longest_even = 0;
            int longest_odd = 0;
            for (int c = 0; c < 26; c++) {
                longest_even = max(longest_even, even_prefix[c][n - 1]);
                longest_odd = max(longest_odd, odd_prefix[c][n - 1]);
            }
            cout << n - (longest_even + longest_odd) << endl;
        } else {
            int ans = n;
            for (int i = 0; i < n; i++) {
                int longest_even = 0;
                int longest_odd = 0;
                for (int c = 0; c < 26; c++) {
                    longest_even = max(longest_even, prefix_sum(even_prefix[c], 0, i - 1) + prefix_sum(odd_prefix[c], i + 1, n - 1));
                    longest_odd = max(longest_odd, prefix_sum(odd_prefix[c], 0, i - 1) + prefix_sum(even_prefix[c], i + 1, n - 1));
                }
                // cout << longest_even << " " << longest_odd << endl;
                ans = min(ans, n - (longest_even + longest_odd));
            }
            // cout << max(n - (longest_even + longest_odd), 1) << endl;
            cout << ans << endl;
            // cout << "Idk" << endl;
        }
    }

    return 0;
}
