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

const int MAXN = 1e5;
bool is_prime[MAXN];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> primes;

    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i < MAXN; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        set<int> seen_primes;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool shared = false;
        for (int i = 0; i < n; i++) {
            for (int prime : primes) {
                if (prime * prime > a[i]) {
                    break;
                }
                if (a[i] % prime != 0) {
                    continue;
                }

                if (seen_primes.count(prime)) {
                    shared = true;
                    break;
                }
                seen_primes.insert(prime);
                while (a[i] % prime == 0) {
                    a[i] /= prime;
                }
            }
            if (a[i] > 1) {
                if (seen_primes.count(a[i])) {
                    shared = true;
                    break;
                }
                seen_primes.insert(a[i]);  // a[i] is prime
            }
        }
        if (shared) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
