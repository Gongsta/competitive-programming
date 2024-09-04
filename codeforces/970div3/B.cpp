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
        string s;
        cin >> s;
        int x = sqrt((double)n);
        // cout << x << endl;
        if (x * x != n) {
            cout << "No" << endl;
        } else {
            bool works = true;
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < x; j++) {
                    // cout << i << " " << j << endl;
                    // cout << s[i * x + j] << endl;
                    if (i == 0 || i == x - 1) {
                        if (s[i * x + j] == '0') {
                            works = false;
                            break;
                        }
                    } else {
                        if (j == 0 || j == x - 1) {
                            if (s[i * x + j] == '0') {
                                works = false;
                                break;
                            }
                        } else {
                            if (s[i * x + j] == '1') {
                                works = false;
                                break;
                            }
                        }
                    }
                }
                if (!works) {
                    break;
                }
            }
            if (works) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
