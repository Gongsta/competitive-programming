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
        int a[n][n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                a[i][j] = j + 1;
            }
            for (int k = 0; k < n; k++) {
                a[k][i] = k + 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += a[i][j];
            }
        }
        cout << sum << " " << 2 * n << endl;
        for (int i = n - 1; i >= 0; i--) {
            cout << 1 << " " << i + 1 << " ";
            for (int j = 0; j < n; j++) {
                cout << j + 1 << " ";
            }
            cout << endl;
            cout << 2 << " " << i + 1 << " ";
            for (int j = 0; j < n; j++) {
                cout << j + 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
