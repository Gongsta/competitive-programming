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
        int n;
        cin >> n;
        int a[n];
        int b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int m;
        cin >> m;
        int d[m];
        map<int, int> mm;
        for (int i = 0; i < m; i++) {
            cin >> d[i];
            mm[d[i]]++;
        }
        bool works = true;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] != b[i]) {
                if (mm[b[i]] <= 0) {
                    works = false;
                    break;
                }
                mm[b[i]]--;
            }
        }
        bool local_works = false;
        for (int i = 0; i < n; i++) {
            if (b[i] == d[m - 1]) {
                local_works = true;
                break;
            }
        }
        works = works && local_works;
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
