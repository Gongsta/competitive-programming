#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
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
        string s;
        string t;
        cin >> s >> t;
        int p = 0;
        bool possible = true;
        string ans;
        for (auto c : t) {
            if (p >= s.size()) {
                possible = false;
                break;
            }

            while (c != s[p] && s[p] != '?') {
                ans += s[p];
                p++;
                if (p >= s.size()) {
                    possible = false;
                    break;
                }
            }
            if (s[p] == '?') {
                ans += c;
            } else {
                ans += s[p];
            }
            p++;
        }
        for (int i = p; i < s.size(); i++) {
            if (s[i] == '?')  {

                ans += 'a';
            } else {

                ans += s[i];
            }
        }
        if (possible) {
            cout << "YES" << endl;
            cout << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
