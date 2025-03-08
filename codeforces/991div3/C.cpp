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

int get_digit_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int square(int n) {
    int last_digit = n % 10;
    int squared = last_digit * last_digit;
    n = (n / 10) * 10;
    if (squared >= 10) {
        n *= 10;
    }
    n += squared;
    return n;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        bool works = false;
        int sum = 0;
        int twos = 0;
        int threes = 0;
        for (char c : n) {
            sum += (c - '0');
            if (c == '2') {
                twos++;
            }
            if (c == '3') {
                threes++;
            }
        }

        for (int i = 0; i <= min(twos, 18ll); i++) {
            for (int j = 0; j <= min(threes, 3ll); j++) {
                int new_sum = sum + i * 2 + j * 6;
                if (new_sum % 9 == 0) {
                    works = true;
                    break;
                }
            }
            if (works) {
                break;
            }
        }
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
