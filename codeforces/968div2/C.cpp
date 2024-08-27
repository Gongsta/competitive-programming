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
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, int> m;
        for (auto c : s) {
            m[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto x : m) {
            pq.push({x.second, x.first});
        }
        string ans;
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            for (int i = 0; i < min(x.first, 1); i++) {
                ans += x.second;
            }
            x.first -= min(x.first, 1);
            if (x.first > 0) {
                pq.push(x);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
