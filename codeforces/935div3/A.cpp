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
        ll a, b, c;
        cin >> a >> b >> c;

        if (b % 3 != 0 && c < 3 - (b % 3)) {
            cout << -1 << endl;
        } else {
            if (b % 3 != 0) {
                c -= (3 - b % 3);
                b += (3 - b % 3);
            }
            ll total = a + b / 3 + c / 3;
            c -= 3 * (c / 3);
            total += c / 2;
            c -= 2 * (c / 2);
            total += c;
            cout << total << endl;
        }
        
    }

    return 0;
}
