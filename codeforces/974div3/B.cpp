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
1 2 3 4
odd - even - odd - even - odd - even - odd - even - odd
        even odd - odd - even - even - odd - odd - even
odd - odd - even - even - odd - odd
1 2 3 4

3 4 6 7 9 10

*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n,k;
        cin >> n >> k;
        ll first_year = (n - k + 1);
        // Starting with odd
        ll duration = (n - first_year) % 4;

        bool even = true;
        if (first_year % 4 == 1 || first_year % 4 == 3) {
            even = false;
        }
        if (even) {
            if (duration == 1 || duration == 2){
                even = false;
            }
        } else {
            if (duration == 2 || duration == 3) {
                even = true;
            }
        }

        if (even) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
