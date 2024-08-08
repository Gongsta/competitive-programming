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

/*
We want to maximize
(n-k) * a + sum(b-k+1, b)

First k buns are sold at:
b
b-1
b-2
b-..
b-k+1

Basically, we need to find the point where b-i+1 = a, at that's the point where we use the original price

b-a+1 = i;


*/
ll sum(ll a, ll b) {
    return b * (b + 1ll) / 2ll - (a) * (a - 1ll) / 2ll;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;
        ll k = 0;
        if (b - a + 1 > 0) {
            k = b - a + 1;
            k = min(k, min(n, b));
        }
        ll ans = (n - k) * a + sum(b - k + 1, b);
        cout << ans << endl;
    }

    return 0;
}
