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
Each light follows a period of k. We want to find a moment when all of them are on.

For 2 lights, the intersection is given by:

Initial just assume they were started some time before k. Because it's periodic.
If one is zero and the over is

It's on every 2k periods for a period of k.

On periods
2-5 8-11
3-6 9-12
5-8 14-17
6-9

64-69 74-79
68-73 78-83
70-75 80-85

ONLY CASE: Impossible if start and end perfectly overlap (i.e. after alignment, start times are off by k)
- NOT TRUE: Also. if off by 1 with 3 numbers.

Else, just take the max of the numbers.

Align the numbers.

*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        ll max_num = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            max_num = max(max_num, a[i]);
        }

        vector<ll> vec;
        for (int i = 0; i < n; i++) {
            // Align to correct starting postion
            a[i] = a[i] + ((max_num - a[i]) / (2 * k)) * (2 * k);
            vec.push_back(a[i]);
        }

        // Only use the needed numbers
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        // for (auto v : vec) {
        //     cout << v << " ";
        // }
        // cout << endl;

        bool works = true;
        n = vec.size();
        // Binary search value, make sure there's no perfect match
        for (ll i = 0; i < n; i++) {
            ll j = lower_bound(vec.begin() + i, vec.end(), vec[i] + k) - vec.begin();
            if (j < n && vec[j] == vec[i] + k) {
                works = false;
                break;
            }
        }
        if (!works) {
            cout << -1 << endl;
        } else {
            // Get the answer
            // Within k periods
            ll ans = vec[0];
            bool ww = false;
            for (ll p = 0; p < k; p++) {
                bool works = true;
                ll new_num = 0;
                for (ll i = 0; i < n; i++) {
                    if (vec[i] >= vec[0] + k) {
                        works = false;
                        new_num = vec[i];
                        break;
                    } else {
                        ans = vec[i];
                    }
                }
                if (works) {
                    ww = true;
                    break;
                } else {
                    for (ll i = 0; i < n; i++) {
                        if (vec[i] + k <= new_num) {
                            vec[i] += 2 * k;
                        }
                    }
                }
                sort(vec.begin(), vec.end());
                // for (auto v : vec) {
                //     cout << v << " ";
                // }
                // cout << endl;
            }
            if (ww) {
                cout << ans << endl;
            } else {
                cout << -1 << endl;  // Answer not found after all tries
            }
        }
    }

    return 0;
}
