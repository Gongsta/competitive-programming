#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
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
        string a;
        string b;
        cin >> a >> b;
        int ans = a.size() + b.size();
        for (int end = b.size() - 1; end >= 0; end--) {
            int p = end;
            for (int i = a.size() - 1; i >= 0; i--) {
                if (p < 0) {
                    break;
                }
                if (b[p] == a[i]) {
                    p--;
                }
            }
            ans = min(ans, (int)a.size() + (p + 1) + ((int)b.size() - 1 - end));
        }
        cout << ans << endl;
    }

    return 0;
}
