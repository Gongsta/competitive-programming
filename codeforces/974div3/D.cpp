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
        int n, d, k;
        cin >> n >> d >> k;
        map<int, int> starts;
        map<int, int> ends;
        for (int i=0;i<k;i++) {
            int l, r;
            cin >> l >> r;
            starts[l]++;
            ends[r + 1]++;
        }
        int l = 1;
        int r = l + d - 1;
        int total_overlaps = 0;
        for (int i = l; i < r; i++) {
            total_overlaps += starts[i];
        }
        int min_overlaps = k;
        int max_overlaps = 0;
        int brother_ans = 1;
        int mother_ans = 1;
        while (r <= n) {
            total_overlaps -= ends[l];
            total_overlaps += starts[r];
            if (total_overlaps < min_overlaps) {
                mother_ans = l;
                min_overlaps = total_overlaps;
            }
            if (total_overlaps > max_overlaps) {
                brother_ans = l;
                max_overlaps = total_overlaps;
            }

            l++;
            r++;
        }
        cout << brother_ans << " " << mother_ans << endl;
    }

    return 0;
}
