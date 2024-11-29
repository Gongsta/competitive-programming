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
#include <vector>
// #include <unordered_map> // NEVER USE THOSE IN CP
// #include <unordered_set> // NEVER USE THOSE IN CP

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            for (int i = 1; i <= n / 2; i++) {
                cout << i << " " << i << " ";
            }
            cout << endl;
        } else if (n % 2 == 1 && n >= 27) {
            int curr = 3;
            for (int i = 1; i <= n; i++) {
                if (i == 1 || i == 10 || i == 26) {
                    cout << 1 << " ";
                } else if (i == 11 || i == 27) {
                    cout << 2 << " ";
                } else {
                    cout << curr << " " << curr << " ";  // double count it
                    i++;
                    curr++;
                }
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
        /*
        If even, just do 1 1 2 2 3 3 and it works
        If odd, figure out a greedy strategy to make it work.
        3^2 + 4^2 = 5^2

        Use that intuition to get a correct answer
        */
    }

    return 0;
}
