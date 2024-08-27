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
        set<int> a;
        set<int> b;
        cin >> n;
        a.insert(1);
        for (int i = 2; i <= n; i++) {
            b.insert(i);
        }
        vector<pair<int, int>> edges;
        int curr = 1;
        while (a.size() < n) {
            int x = *b.begin();
            int mid = -1;
            while (true) {
                cout << "? " << curr << " " << x << endl;
                cin >> mid;
                if (mid == -1) {
                    return -1;
                }
                if (mid == curr) {
                    edges.push_back({curr, x});
                    a.insert(x);
                    b.erase(x);
                    break;
                } else if (a.count(mid)) {
                    curr = mid;
                } else {
                    x = mid;
                }
            }
        }
        cout << "! ";
        for (auto e : edges) {
            cout << e.first << " " << e.second << " ";
        }
        cout << endl;
    }

    return 0;
}
