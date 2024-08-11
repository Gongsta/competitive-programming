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
        int n, k;
        cin >> n >> k;
        int ans = 1;
        if (k == 0) {
            ans = 0;
        }
        k -= n;
        int count = 1;
        while (k > 0) {
            count++;
            if (count == 2) {
                n--;
                count = 0;
            }
            k -= n;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
