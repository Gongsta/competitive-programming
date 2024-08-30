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
        int l, r;
        cin >> l >> r;
        int add = 0;
        int base = (r - l + 1) / 4;
        if ((l % 2 == 1 || r % 2 == 1) && (r - l + 1) - 4 * base == 3) {
            add++;
        }
        cout << base + add << endl;
    }

    return 0;
}
