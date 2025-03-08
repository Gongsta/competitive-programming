#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
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
#include <vector>

// #include <unordered_map> // NEVER USE THOSE IN CP
// #include <unordered_set> // NEVER USE THOSE IN CP

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

/*
There always exist the solution where you make all letters the same.

There are a few options:
- Replace the letter with the most popular letter
- Combine 2 less popular letters, changing only the other one

idea: Find the shortest distance where it has a balance of x (all letters have a count of
x in the string), n/x = k -> k characters

greedy might work, (my idea was you should always go for the most common letter)
appaallz -> doesn't work replacing into 'a', you should actually be replacing 'a' with 'z'
- so 1 edit away

So with the x idea, you can just use the factors of n, so do that in sqrt(x)

And since you store the character count. can't you just figure out a O(26*26) solution?
Swap those who have exceeded with a value of those who have not exceeded.

If no more that have exceeded, pick one that has not exceeded?? But that should be replaced too??

But also, reconstructing the string is not obvious??

*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        map<char, int> m;
        for (auto x : s) {
            m[x]++;
        }

        int best_k = 1;  // k is the number of different characters
        int min_swaps = s.size();
        vector<pair<int, char>> chars;
        for (auto x : m) {
            chars.push_back({x.second, x.first});
        }
        sort(chars.begin(), chars.end(), greater<pair<int, char>>());
        for (int k = 1; k <= 26; k++) {
            if (n % k != 0) {
                continue;
            }
            int char_count = n / k;
            int kept = 0;
            for (int i = 0; i < min(k, (int)chars.size()); i++) {
                kept += min(chars[i].first, char_count);
            }
            if (n - kept < min_swaps) {
                min_swaps = n - kept;
                best_k = k;
            }
        }
        // so now we know our target k
        int char_count = n / best_k;
        map<char, int> letters;  // stores number of letters needed to visit before removing
        map<char, int> skip;
        for (int i = 0; i < best_k; i++) {
            if (i >= chars.size()) {
                for (int j = 0; j < 26; j++) {
                    if (!letters.count(j + 'a')) {
                        letters[j + 'a'] = char_count;
                        break;
                    }
                }
            } else {
                letters[chars[i].second] = max(char_count - chars[i].first, 0ll);
                skip[chars[i].second] = min(char_count, chars[i].first);
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (skip[s[i]] > 0) {
                skip[s[i]]--;
            } else {
                for (int j = 0; j < 26; j++) {
                    if (letters[j + 'a'] > 0) {
                        letters[j + 'a']--;
                        s[i] = (j + 'a');
                        break;
                    }
                }
            }
        }
        cout << min_swaps << endl;
        cout << s << endl;
    }

    return 0;
}
