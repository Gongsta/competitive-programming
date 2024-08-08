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

Always try to greedily reach the logs first. Jump first, then swim.
Because you can't swim and jump.

This is optimal solution. If greedy solution says yes, it's true, just look at greedy soltuion.
Assume that greedy solution says no but it's yes. Let l be the first log. We already considered that solution, since we always
go for the shorter log and reset.

Ok, misunderstood the question.



*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string a;
        cin >> a;
        a = 'L' + a;
        a = a + 'L';

        bool possible = true;
        int i = 0;
        int swim_dist = 0;
        while (i < a.size()) {
            // cout << i << " " << a[i] << " ";
            if (a[i] == 'L' && a[i + 1] != 'L') {  // Start the jump
                int jump_dist = 1;
                i++;
                while (i < a.size() && a[i] != 'L') {  // Keep jumping until we reach the closest log so we reset the jump
                    jump_dist++;
                    if (jump_dist > m) {
                        break;
                    }
                    i++;
                }
            } else if (a[i] == 'W') {
                while (i < a.size() && a[i] == 'W') {
                    i++;
                    swim_dist++;
                    if (swim_dist > k) {
                        possible = false;
                        break;
                    }
                }
            } else if (a[i] == 'C') {
                possible = false;
                break;
            } else if (a[i] == 'L') {  // log and log
                i++;
            } else {
                throw;
            }
        }
        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
