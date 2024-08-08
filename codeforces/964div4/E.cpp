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
        int l, r;
        cin >> l >> r;
        int ops = 0;
        int a = l;
        while (a != 0) {
            ops++;
            a /= 3;
        }
        ops *= 2;  // number of ops to reset b back to its number
        int num = 3;
        int num_ops = 1;
        while (num <= l + 1) {
            num *= 3;
            num_ops++;
        }

        for (int i = l + 1; i <= r; i++) {
            while (num <= i) {
                num *= 3;
                num_ops++;
            }
            ops += num_ops;
        }
        cout << ops << endl;
    }

    return 0;
}
