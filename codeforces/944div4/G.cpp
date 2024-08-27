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
/*
XOR < 4, means for the bits that differ, it should be less than 4. Meaning it can only differ on the 1st and 2nd bit (and any difference for those)
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        map<int, queue<int>> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]].push(i);
        }
        for (int i = 0; i < n; i++) {
            int min_val = (a[i] >> 2) << 2;
            for (int val = min_val; val < a[i]; val++) {
                while (m.count(val) && !m[val].empty()) {
                    int j = m[val].front();
                    m[val].pop();
                    if (j > i) {
                        swap(a[i], a[j]);
                        m[a[j]].push(j);
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
