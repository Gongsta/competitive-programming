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

// #define INT_MAX 2147483647

typedef long long ll;

using namespace std;

/*
First observation: final string constructed always has the same number, and it's 'n'.
Therefore, we only need to consider 'n', 'nn', 'nnn', etc'. But this n can be more than a digit.

n = a n - b

(an - b) + b = an

Is there a relationship?
2 vs. 22222
10 vs 101010
30 vs. 303030
But can also be 30303, since you take off b.



*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        string s;
        for (int a = 1; a <= 10000; a++) {
            s += to_string(n);
            // Binary search for the value of b
            int l = 1;
            int r = s.size();
            string l_val_str = s;
            while (l <= r) {
                int b = (r + l) / 2;
                int r_val = n * a - min(b, n * a);
                string l_val_str;
                if (b > (int)s.size()) {
                    l_val_str = "";
                } else {
                    l_val_str = s.substr(0, (int)s.size() - b);
                }
                int l_val = -1;
                if (l_val_str.size() > 8) {
                    l_val = INT_MAX;

                } else if (!l_val_str.empty()) {
                    l_val = stoi(l_val_str);
                }
                int target = l_val - r_val;
                if (target == 0) {
                    v.push_back({a, b});
                    break;
                } else if (target < 0) {
                    r = b - 1;
                } else {
                    l = b + 1;
                }
            }
        }
        cout << v.size() << endl;
        for (auto& p : v) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}
