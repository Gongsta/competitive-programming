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
        int xc, yc, k;
        cin >> xc >> yc >> k;
        for (int i = 1; i <= k / 2; i++) {
            cout << xc - i << " " << yc - i << endl;
            cout << xc + i << " " << yc + i << endl;
        }
        if (k % 2 == 1) {
            cout << xc << " " << yc << endl;
        }
    }

    return 0;
}
