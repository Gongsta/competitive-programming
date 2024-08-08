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
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        int ans = 0;
        /*
        a1b1 a2b2
        a1b2 a2b1
        a2b1 a1b2
        a2b2 a1b1
        */
        if (a1 >= b1 && a2 >= b2) {
            if (a1 > b1 || a2 > b2) {
                ans += 2;
            }
        }
        if (a2 >= b1 && a1 >= b2) {
            if (a2 > b1 || a1 > b2) {
                ans += 2;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
