#include <algorithm>
#include <bitset>
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
Reason about the greedy algorithm, there's something I'm doing wrong.


Algo:
Go through the sorted array, and increase the even number if possible. Else, use the biggest odd number so this number increases as fast as possible.

Assume by contradiction that there is a faster algo than this, that means some number was used less than normal. That can't be, the biggest odd added
will always make the solution converge the fastest...

1 4 6 8

1 5 6 8
1 11 6 8
1 11 17 8
1 11 17 25

1 4 6 9
1 13 6 9

*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        ll biggest_odd = 1;
        ll biggest_even = 0;
        int even = 0;
        int odd = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 1) {
                biggest_odd = max(biggest_odd, a[i]);
                odd++;
            }
        }
        sort(a, a + n);

        if (odd == 0) {
            cout << 0 << endl;
        } else {
            for (int i = 0; i < n; i++) {
                if (a[i] % 2 == 0 && a[i] < biggest_odd) {
                    even++;
                    a[i] += biggest_odd;
                    biggest_odd = max(biggest_odd, a[i]);
                } else if (a[i] % 2 == 0) {
                    even++;
                    biggest_even = a[i];
                }
            }

            // Add the largest number, all other numbers will be smaller
            if (biggest_even > biggest_odd) {
                even++;
            }

            cout << even << endl;
        }
    }

    return 0;
}
