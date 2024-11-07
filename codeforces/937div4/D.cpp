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

/*
11
11
121
 11
 121
121
1331
*/

vector<int> binary_nums;

bool is_binary(int n) {
    while (n > 0) {
        if (n % 10 > 1) {
            return false;
        }
        n /= 10;
    }
    return true;
}
bool search(int n) {
    if (is_binary(n)) {
        return true;
    }
    bool works = false;
    for (auto v : binary_nums) {
        if (v > n) {
            break;
        }
        if (n % v == 0) {
            works |= search(n / v);
        }
    }
    return works;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i < 50001; i++) {
        if (is_binary(i)) {
            binary_nums.push_back(i);
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (search(n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
