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

vector<int> curr_set;
bool visited[200001];
int curr_set_total;
char s[200001];
int p[200001];

void dfs(int i) {
    if (visited[i]) {
        return;
    }
    visited[i] = true;
    if (s[i] == '0') {
        curr_set_total++;
    }
    curr_set.push_back(i);
    // cout << i << " " << curr_set_total << endl;
    dfs(p[i]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        int cnt[n + 1];
        memset(cnt, 0, sizeof(cnt));
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                curr_set_total = 0;
                curr_set.clear();
                dfs(i);
                for (auto x : curr_set) {
                    cnt[x] = curr_set_total;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << cnt[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
