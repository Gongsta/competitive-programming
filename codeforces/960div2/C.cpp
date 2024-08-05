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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    // 0 2 2 3 3 5 5
    // 0 0 2 2 3 3 5
    // 0 0 0 2 2 3 3

    // 3 2 2 3

    // Either Replace with number before, or be set to 0
    /*
    Get initial sum, and apply operation twice (computing sum). You will only be left with numbers that appear twice, or if they appear only once, it's at the right side
    // Predict the contribution that each number will have (a[i] * (n-i)), but check that this number is there at least twice
    // Numbers on right side never get dropped, since there will always be at least 2 of them.

    */
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll sum = 0;
        ll top_pair = -1;
        for (int j = 0; j < 2; j++) {
            top_pair = -1;
            set<int> s;
            vector<ll> tmp(n);
            for (int i = 0; i < n; i++) {
                sum += a[i];
                if (s.count(a[i])) {
                    if (top_pair == -1) {
                        top_pair = a[i];
                    } else {
                        top_pair = max(top_pair, a[i]);
                    }
                } else {
                    s.insert(a[i]);
                }

                if (top_pair == -1) {
                    tmp[i] = 0;
                } else {
                    tmp[i] = top_pair;
                }
            }

            a = tmp;
        }

        for (ll i = 0; i < n; i++) {
            sum += a[i] * (n - i);
        }
        cout << sum << endl;
    }

    return 0;
}
