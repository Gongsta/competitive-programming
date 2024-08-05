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
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        x--;
        y--;
        int a[n];
        for (int i = y; i <= x; i++) {
            a[i] = 1;
        }
        bool used = false;
        for (int i = y - 1; i >= 0; i--) {
            if (used) {
                a[i] = 1;
            } else {
                a[i] = -1;
            }
            used = !used;
        }

        used = false;
        for (int i = x + 1; i < n; i++) {
            if (used) {
                a[i] = 1;
            } else {
                a[i] = -1;
            }
            used = !used;
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
