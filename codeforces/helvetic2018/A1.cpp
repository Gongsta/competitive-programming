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
#include <vector>
// #include <unordered_map> // NEVER USE THOSE IN CP
// #include <unordered_set> // NEVER USE THOSE IN CP

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

void rotate(vector<vector<char>>& g) {
    int n = g.size();
    for (int i = 0; i < n / 2 + n % 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            int tmp = g[i][j];
            g[i][j] = g[n - 1 - j][i];
            g[n - 1 - j][i] = g[n - 1 - i][n - 1 - j];
            g[n - 1 - i][n - 1 - j] = g[j][n - 1 - i];
            g[j][n - 1 - i] = tmp;
        }
    }
}
void flip_v(vector<vector<char>>& g) {
    int n = g.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(g[i][j], g[i][n - 1 - j]);
        }
    }
}

void flip_h(vector<vector<char>>& g) {
    int n = g.size();

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n / 2; i++) {
            swap(g[i][j], g[n - 1 - i][j]);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<char>> g1(n, vector<char>(n));
    vector<vector<char>> g2(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g1[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g2[i][j];
        }
    }
    bool match = false;
    for (int i = 0; i < 4; i++) {
        if (g1 == g2) {
            match = true;
            break;
        }
        flip_v(g1);
        if (g1 == g2) {
            match = true;
            break;
        }
        flip_v(g1);
        rotate(g1);
        if (g1 == g2) {
            match = true;
            break;
        }
        flip_h(g1);
        if (g1 == g2) {
            match = true;
            break;
        }
        flip_h(g1);
    }
    if (match) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
