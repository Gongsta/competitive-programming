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

// You need at least a >= log(c)
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 0 && b == 0 && a == 0) {
            cout << 0 << endl;
        } else if (c == 1 && a == 0) {
            cout << b << endl;
        } else if (c > 1 && a == c - 1) {
            int min_height = (int)(log2(c - 1)) + 1;
            int free_b = (1 << min_height) - c;
            b -= free_b;
            if (b > 0) {
                min_height += b / c;
                if (b % c != 0) {
                    min_height++;
                }
            }
            cout << min_height << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
