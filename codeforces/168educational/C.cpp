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
        string s;
        cin >> s;
        int closed_to_add = 0;
        for (auto c : s) {
            if (c == '(') {
                closed_to_add++;
            }
        }
        int count = 0;
        string optimal_s;
        vector<int> open;
        vector<int> closed;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c == '_') {
                if (closed_to_add > 0 && count > 0) {
                    closed_to_add--;
                    optimal_s += ')';
                } else {
                    optimal_s += '(';
                }
            } else {
                optimal_s += c;
            }

            if (optimal_s[optimal_s.length() - 1] == '(') {
                count++;
                open.push_back(i);
            } else {
                count--;
                closed.push_back(i);
            }
        }
        int score = 0;
        for (int i = 0; i < open.size(); i++) {
            score += closed[i] - open[i];
        }
        cout << score << endl;
    }

    return 0;
}
