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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int even_max = 0;
        int odd_max = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even_max = max(even_max, a[i]);
            } else {
                odd_max = max(odd_max, a[i]);
            }
        }
        cout << max(even_max + n / 2 + n % 2, odd_max + n / 2) << endl;
    }

    return 0;
}
