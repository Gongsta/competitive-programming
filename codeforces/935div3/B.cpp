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

/*
a-------2a---------3a--------4a----
b--2b--3b--4b--5b--6b

*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll a, b, m;
        cin >> a >> b >> m;
        ll num_a = (m / a) + 1;
        ll num_b = (m / b) + 1;
        cout << num_a + num_b << endl;
    }

    return 0;
}
