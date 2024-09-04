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
        for (int i=0;i<2*n;i++) {
            for (int j=0;j<2*n;j++) {
                if ((i % 4 < 2 && j % 4 < 2) || (i % 4 >= 2 &&  j % 4 >= 2)) {
                    cout << '#';
                } else {
                    cout << '.';
                }
            }
            cout << endl;

        }
    }

    return 0;
}
