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
Consider 14, which is 1110 in binary

We want to construct the longest sequence, can be done in a greedy fashion.
- Always prove quickly that this is the optimal solution.


How to write this algorithm in code?
- Start from biggest (original number) to smallest, do an XOR to find the minimal number, and make that number as big as possible while
ensuring that it's smaller than the previous number
while still satisfying the constraint

1010
1100
1110


*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> ans;
        ans.push_back(n);
        while (true) {
            ll old_num = ans.back();
            ll new_num = n ^ old_num;
            if (new_num > old_num) {
                break;
            }
            // Add ones while still ensuring that new_num is smaller than old_num, do from biggest bits first
            ll shift = 62;
            while (shift > 0) {
                if (!((new_num >> shift) & 1) && ((old_num >> shift) & 1) && (new_num + (1ll << shift)) < old_num) {
                    new_num += 1ll << shift;
                }
                shift--;
            }
            if (new_num == 0) {
                break;
            }
            ans.push_back(new_num);
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto s : ans) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
