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
        int n, r;
        cin >> n >> r;
        int a[n];
        int ans = 0;
        int solos = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            r -= a[i] / 2;
            if (a[i] % 2 == 0) {
                ans += a[i];
            } else {
                ans += a[i] - 1;
                solos++;
            }
        }
        while (solos > r) {
            r--;
            solos -= 2;
        }
        cout << ans + solos << endl;
    }

    return 0;
}
