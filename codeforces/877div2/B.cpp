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
        int min_i = 0;
        int mid_i = 0;
        int max_i = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                min_i = i;
            }
            if (a[i] == 2) {
                mid_i = i;
            }
            if (a[i] == n) {
                max_i = i;
            }
        }
        if (min_i > mid_i) {
            swap(min_i, mid_i);
        }
        if (min_i < max_i && max_i < mid_i) {
            cout << "1 1" << endl;
        } else if (max_i < min_i) {
            cout << max_i + 1 << " " << min_i + 1 << endl;
        } else {
            cout << max_i + 1 << " " << mid_i + 1 << endl;
        }
    }

    return 0;
}
