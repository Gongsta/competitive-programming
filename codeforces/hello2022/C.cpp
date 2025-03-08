#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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

/*
3 2 1

1 2 3
3 2 1
1 2 3

ref
4 2 1 3

1 2 3 4
4 2 1 3
3 2 4 1
1 2 3 4

*/
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
        int p[n + 1];
        bool visited[n + 1];
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                continue;
            }
            cout << "? " << i << endl;
            int x;
            cin >> x;
            while (!visited[x]) {
                cout << "? " << i << endl;
                visited[x] = true;
                int y;
                cin >> y;
                p[x] = y;
                x = y;
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
