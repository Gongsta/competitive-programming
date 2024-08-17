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
// Decreasing, decreasing is not possible
// 15 7 5 30
// 1 1 6

bool solve(vector<int>& a, int gt_idx) {
    vector<int> gcd_arr;
    vector<int> a_fixed;

    for (int i = 0; i < a.size(); i++) {
        if (i != gt_idx) {
            a_fixed.push_back(a[i]);
        }
    }

    for (int i = 1; i < a_fixed.size(); i++) {
        gcd_arr.push_back(gcd(a_fixed[i - 1], a_fixed[i]));
    }
    bool works = true;
    for (int i = 1; i < gcd_arr.size(); i++) {
        if (gcd_arr[i - 1] > gcd_arr[i]) {
            works = false;
            break;
        }
    }
    return works;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> gcd_arr;
        for (int i = 1; i < n; i++) {
            gcd_arr.push_back(gcd(a[i - 1], a[i]));
        }
        int gt_idx = 0;
        for (int i = 1; i < n - 1; i++) {
            if (gcd_arr[i - 1] > gcd_arr[i]) {
                gt_idx = i - 1;
                break;
            }
        }
        // try again removing the number, 3 different options
        bool works = false;
        works = works || solve(a, gt_idx);
        works = works || solve(a, gt_idx + 1);
        works = works || solve(a, gt_idx + 2);

        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
