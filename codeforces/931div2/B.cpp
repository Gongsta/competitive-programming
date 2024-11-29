#include <iostream>
#include <vector>
using namespace std;

#define int long long  // To handle large numbers

int triangular_coins[] = {1, 3, 6, 10, 15};

/*
1 is used at most 2x
3 is used at most 1x
6 is used at most 2x
10 is used at most 2x
15 is used as many times as needed

So you exhaustively search this
*/

int INF = 1e9;
int min_coins(int n, int i, int ans) {
    if (n < 0) {
        return INF;
    }
    if (n == 0) {
        return ans;
    }

    int count = INF;
    for (int j = i; j < 5; j++) {
        if (j != 4) {
            // use once
            count = min(count, min_coins(n - triangular_coins[j], j + 1, ans + 1));
            if (j != 1) {
                count = min(count, min_coins(n - 2 * triangular_coins[j], j + 1, ans + 2));
            }
        } else {
            count = min(count, min_coins(n % triangular_coins[j], j + 1, ans + n / triangular_coins[j]));
        }
    }
    return count;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n;
        cin >> n;  // Target value
        cout << min_coins(n, 0, 0) << "\n";
    }

    return 0;
}
