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
        // Use a priority queue potentially??
        // Use a max heap
        // 5 4 3 2 1 -> worst case complexity? O(n^2), that's really bad
        // it goes like this
        /*
        5 4 3 2 1
        1 6 5 4 3
        1 3 7 6 4

        Look at it in reverse order. As long as a[i-1] <= a[i], we're good.o

        3 2 1 3 2 1

        If it is violated, those need to be moved.
        */
        stack<int> s;
        queue<int> q;
        int n;
        cin >> n;
        int a[n];
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            if (s.empty()) {
                s.push(a[i]);
            } else {
                if (a[i] >= s.top()) {
                    s.push(a[i]);
                } else {
                    // 3 1 // for example
                    while (!s.empty() && s.top() < a[i]) {
                        q.push(s.top() + 1);
                        s.pop();
                    }
                    s.push(a[i]);
                }
            }
        }

        return 0;
    }
