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

/*
Let's think about some strategies here, and figure out the optimal one.

Given that the XOR of the numbers are some number. noo, that's too complicated

Use the set, because duplicate numbers don't matter.
Then, you can just check the parity?

Alice wins if she can end on an even turn.
Bob wins if he can win on an odd turn.

Actually no, the person who reaches the last wins.
The first person who reaches the second to last wins? (unless it's 1)
- Because they can clear k-1 items, and then that person has to clear 1 item. But it's more complicated
- If they don't fully clear the pile, the other person also doesn't fully clear the pile. Therefore it's odd.

1 2 3 4 7 9 100

If there is a gap of 1, it's never possible to be in control. Else, we can change

2 3 5 6 7 9

It's a little more complicated

*/
using namespace std;

char swap_player(char player) {
    if (player == 'A') {
        return 'B';
    }
    return 'A';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        char p = 'A';
        int n;
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        vector<int> v;
        for (auto x : s) {
            v.push_back(x);
        }
        int dec = 0;
        int i = 0;
        while (i < v.size() - 1) {
            if (v[i] - dec == 1) {  // only option is to decrement
                dec++;
                p = swap_player(p);
                i++;
            } else {  // we can choose to play the next one or not
                // Count the number of times that we don't have choices
                int consec = 0;
                for (int j = i + 1; j < v.size() - 1; j++) {
                    if (v[j] - v[j - 1] == 1) {
                        consec++;
                    } else {
                        break;
                    }
                }
                if ((v.size() - 1 - (i + 1 + consec)) % 2 == 0) {  // we are on track, let the other player play the next one
                    p = swap_player(p);
                }
                dec += v[i] - dec;
                i = i + 1 + consec;
            }
        }
        if (p == 'A') {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }

    return 0;
}
