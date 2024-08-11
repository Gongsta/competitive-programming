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
        int n,m,k;
        cin >> n >> m >> k;
        if (k < n && k < m) {
            cout << k * k << endl;
        } else if (k <= min(n,m)) {
            cout << k * min(n, m) << endl;
        } else {
            int a[3];
            a[0]= k;
            a[1] = n;
            a[2] = m;
            sort(a, a+3);
            cout << a[0] * a[1] << endl;

        }
    }

    return 0;
}
