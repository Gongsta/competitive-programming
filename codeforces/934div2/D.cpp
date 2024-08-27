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

class HashedString {
   private:
    // change M and B if you want
    static const long long M = 1e9 + 9;
    static const long long B = 9973;

    // pow[i] contains B^i % M
    static vector<long long> pow;

    // p_hash[i] is the hash of the first i characters of the given string
    vector<long long> p_hash;

   public:
    HashedString(const string& s) : p_hash(s.size() + 1) {
        while (pow.size() <= s.size()) {
            pow.push_back((pow.back() * B) % M);
        }

        p_hash[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
        }
    }

    long long get_hash(int start, int end) {
        long long raw_val =
            (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
        return (raw_val % M + M) % M;
    }
};
vector<long long> HashedString::pow = {1};

typedef long long ll;

using namespace std;

int prefix_sum(vector<int>& prefix, int l, int r) {
    if (l == 0) {
        return prefix[r];
    } else {
        return prefix[r] - prefix[l - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        HashedString hashed_s{s};
        string reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end());
        HashedString hashed_rev_s{reversed_s};

        vector<int> prefix[26];
        for (int c = 0; c < 26; c++) {
            for (int i = 0; i < n; i++) {
                int add = 0;
                if (s[i] == ('a' + c)) {
                    add = 1;
                }
                if (i == 0) {
                    prefix[c].push_back(add);
                } else {
                    prefix[c].push_back(prefix[c].back() + add);
                }
            }
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            // 2,3,4, ... (r-l + 1);
            ll ans = 1;
            // Consider the even numbers first
            if (prefix_sum(prefix[(s[l] - 'a')], l, r) == (r - l + 1)) {


            }
            (s[l] - 'a')
        }
    }

    return 0;
}
