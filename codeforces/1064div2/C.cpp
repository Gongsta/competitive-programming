#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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

int link[(int)2e5 + 1];
int siz[(int)2e5 + 1];
int arr[(int)2e5 + 1];

int find(int x) {
    if (x == link[x]) {
        return x;
    }
    return link[x] = find(link[x]);
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (arr[a] > arr[b]) {
        swap(a, b);  // Connect the smaller set to the bigger set
    }
    link[a] = b;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            link[i] = i;
        }
        map<int, vector<pair<int, int>>> m;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int max_val = max(arr[i], arr[(i + 1) % n]);
            m[max_val].push_back({i, (i + 1) % n});
        }
        int counter = 0;
        for (auto& x : m) {
            for (auto& v : x.second) {
                counter++;
                if (counter == n) {
                    break;
                }
                unite(v.first, v.second);
                ans += arr[find(v.first)];
            }
            if (counter == n) {
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
