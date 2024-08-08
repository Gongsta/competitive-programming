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
        int n, s, m;
        cin >> n >> s >> m;
        int l[n];
        int r[n];
        bool possible = false;
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
        }
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (l[i] - 0 >= s) {
                    possible = true;
                }
            } else {
                if (l[i] - r[i - 1] >= s) {
                    possible = true;
                }
            }
        }
        if (m - r[n - 1] >= s) {
            possible = true;
        }
        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
