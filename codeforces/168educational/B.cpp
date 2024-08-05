#include <algorithm>
#include <bitset>
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
        int n;
        cin >> n;
        string s1;
        string s2;
        cin >> s1;
        cin >> s2;
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            if (s1[i] == s1[i + 2] && s1[i + 1] == '.' && s1[i] == 'x' && s2[i] != 'x' && s2[i + 2] != 'x') {
                ans += 1;
            }

            if (s2[i] == s2[i + 2] && s2[i + 1] == '.' && s2[i] == 'x' && s1[i] != 'x' && s1[i + 2] != 'x') {
                ans += 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
