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
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        for (int i=0;i<n;i++) {
            cin >> b[i];
        }
        int pa = 0;
        int pb = 0;
        while (pb < n) {
            if (a[pa] <= b[pb]) {
                pa++;
                pb++;
            } else {
                pb++;

            }
        }
        cout << n - pa << endl;
    }

    return 0;
}
