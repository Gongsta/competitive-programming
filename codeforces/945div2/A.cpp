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
        int p[3];
        cin >> p[0] >> p[1] >> p[2];

        int sum = p[0] + p[1] + p[2];
        sort(p, p + 3);
        if (sum % 2 == 1) {
            cout << -1 << endl;
        } else {
            cout << min(sum / 2, p[0] + p[1]) << endl;
        }
    }

    return 0;
}
