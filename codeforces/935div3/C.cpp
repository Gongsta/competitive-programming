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

int prefix_sum(vector<int>& arr, int l, int r) {
    if (l == 0) {
        return arr[r];
    }
    return arr[r] - arr[l - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> num_left;
        vector<int> num_right;
        for (int i = 0; i < n; i++) {
            int last_left_num = 0;
            int last_right_num = 0;
            if (i != 0) {
                last_left_num = num_left.back();
                last_right_num = num_right.back();
            }
            if (s[i] == '0') {
                num_left.push_back(last_left_num + 1);
                num_right.push_back(last_right_num);
            } else {
                num_left.push_back(last_left_num);
                num_right.push_back(last_right_num + 1);
            }
        }
        int ans_i = -1;
        for (int i = -1; i < n; i++) {
            int num_left_happy = 0;
            int num_right_happy = 0;
            if (i >= 0) {
                num_left_happy = prefix_sum(num_left, 0, i);
            }
            if (i < n - 1) {
                num_right_happy = prefix_sum(num_right, i + 1, n - 1);
            }
            if (num_left_happy >= ceil((i + 1.0) / 2.0) && num_right_happy >= ceil((n - i - 1.0) / 2.0)) {
                // cout << i << " " << num_left_happy << " " << num_right_happy << endl;
                if (ans_i == -1) {
                    ans_i = i + 1;
                } else {
                    // check if closer to mid
                    if (abs((double)n / 2.0 - (i + 1)) < abs((double)n / 2.0 - ans_i)) {
                        ans_i = i + 1;
                    }
                }
            }
        }
        cout << ans_i << endl;
    }

    return 0;
}
