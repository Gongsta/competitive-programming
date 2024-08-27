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

Observation: 1 person's position is different when we look at 2 different people being removed.

Solve it in reverse order. So assume the last person is excluded. And then as you solve, you update the best position
*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        ll a[n + m + 1][2];
        for (int i = 0; i < n + m + 1; i++) {
            cin >> a[i][0];
        }
        for (int i = 0; i < n + m + 1; i++) {
            cin >> a[i][1];
        }
        vector<ll> ans;
        vector<ll> dec;

        ll score = 0;
        int n_tmp = n;
        int m_tmp = m;
        int sub_optimal = -1;
        int choice = -1;
        for (int i = 0; i < n + m; i++) {  // Exclude last player
            if (n_tmp == 0) {
                score += a[i][1];
                if (a[i][0] > a[i][1] && sub_optimal == -1) {
                    sub_optimal = i;
                }
                dec.push_back(1);
                choice = 0;
                m_tmp--;
            } else if (m_tmp == 0) {
                score += a[i][0];
                if (a[i][0] <= a[i][1] && sub_optimal == -1) {
                    sub_optimal = i;
                }
                dec.push_back(0);
                choice = 1;  // meaning as soon as testing slot frees up, we pick testing
                n_tmp--;
            } else {
                if (a[i][0] > a[i][1]) {
                    score += a[i][0];
                    n_tmp--;
                    dec.push_back(0);
                } else {
                    score += a[i][1];
                    m_tmp--;
                    dec.push_back(1);
                }
            }
        }
        ll final_score = score;
        for (int i = 0; i < n + m; i++) {
            if (sub_optimal != -1 && choice == dec[i]) {  // free up slot
                int x = sub_optimal;
                ans.push_back(score - a[i][dec[i]] - a[x][dec[x]] + a[x][dec[i]] + a[n + m][dec[x]]);
            } else {  // useless spot
                ans.push_back(score - a[i][dec[i]] + a[n + m][dec[i]]);
            }
        }
        ans.push_back(score);

        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
