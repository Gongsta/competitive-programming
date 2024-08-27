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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int max_interval = 1;
        for (int b = 0; b < 20; b++) {
            int curr_b = 1 << b;
            int local_interval = 0;
            bool seen = false;
            for (int i = 0; i < n; i++) {
                local_interval++;
                if ((a[i] & curr_b) > 0) {
                    max_interval = max(max_interval, local_interval);
                    seen = true;
                    local_interval = 0;
                }
            }
            if (seen) {  // encountered this bit before
                max_interval = max(max_interval, local_interval+1);
            }
        }
        cout << max_interval << endl;
    }

    return 0;
}
