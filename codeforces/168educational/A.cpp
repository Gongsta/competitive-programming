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
        string s;
        cin >> s;
        bool used = false;
        for (int i = 0; i < s.length(); i++) {
            cout << s[i];
            if (i < s.length() - 1 && s[i + 1] == s[i] && !used) {
                used = true;
                if (s[i] == 'a') {
                    cout << 'z';
                } else {
                    cout << 'a';
                }
            }
        }
        if (!used) {
            if (s[s.length() - 1] == 'a') {
                cout << 'z';
            } else {
                cout << 'a';
            }
        }
        cout << endl;
    }

    return 0;
}
