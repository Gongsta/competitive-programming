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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int ind[m];
        for (int i = 0; i < m; i++) {
            cin >> ind[i];
        }
        string c;
        cin >> c;
        sort(c.begin(), c.end());
        set<int> ss;
        for (int i = 0; i < m; i++) {
            ss.insert(ind[i] - 1);  // 0-indexed
        }
        int p = 0;
        for (int x : ss) {
            s[x] = c[p];
            p++;
        }
        cout << s << endl;
    }

    return 0;
}
