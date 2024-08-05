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
        int ones = 0;
        int zeros = 0;
        int n;
        string s;
        cin >> n >> s;
        int first_z = -1;
        int last_z = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ones++;
            } else if ((i > 0 && s[i - 1] == '1') || (i == 0)) {
                zeros++;
            }
        }
        if (ones > zeros) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
