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
        int k, q;
        cin >> k >> q;
        int a[k];
        int n[q];
        int min_num = 100;
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            min_num = min(a[i], min_num);
        }
        for (int i = 0; i < q; i++) {
            cin >> n[i];
            cout << min(min_num-1, n[i]) << " ";
        }
        cout << endl;
    }

    return 0;
}
