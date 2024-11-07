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

vector<int> divisors(int n) {
    vector<int> div;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i != n / i) {
                div.push_back(n / i);
            }
        }
    }
    sort(div.begin(), div.end());
    return div;
}

bool compare(string& s, string& target) {
    int num_diff = 0;
    for (int i=0;i<s.size();i++) {
        if (s[i] != target[i]) num_diff++;
    }
    if (num_diff > 1) {
        return false;
    }
    return true;
}

    int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        int n;
        cin >> n;
        cin >> s;
        vector<int> div = divisors(n);
        int ans = 0;
        for (auto d : div) {
            string prefix = s.substr(0, d);
            string suffix = s.substr(n - d, d);
            string full_prefix;
            string full_suffix;
            for (int i = 0; i < n / d; i++) {
                full_prefix += prefix;
                full_suffix += suffix;
            }
            if (compare(full_prefix, s) || compare(full_suffix, s)) {
                ans = d;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
