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

vector<int> primes;
const int MAXN = 3e5;
bool is_prime[MAXN + 1];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(is_prime, is_prime + MAXN, true);
    is_prime[0] = false;
    is_prime[1] = false;

    map<int, int> prime_to_idx;
    for (int i = 2; i <= MAXN; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            prime_to_idx[i] = primes.size() - 1;
            for (int j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int n;
    cin >> n;
    int N = n + primes.size();
    int a[N];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < primes.size(); i++) {
        a[i + n] = primes[i];
    }

    vector<int> adj[N];
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < primes.size(); i++) {
            if (primes[i] * primes[i] > a[j]) {
                break;
            }
            if (a[j] % primes[i] == 0) {
                adj[i + n].push_back(j);
                adj[j].push_back(i + n);
            }
            while (a[j] % primes[i] == 0) {
                a[j] /= primes[i];
            }
        }
        if (a[j] > 1) {
            int idx = prime_to_idx[a[j]];
            adj[idx + n].push_back(j);
            adj[j].push_back(idx + n);
        }
    }

    int s, t;
    cin >> s >> t;
    s--;
    t--;
    queue<int> q;
    q.push(s);
    int prev[N];
    bool visited[N];
    fill(visited, visited + N, false);
    visited[s] = true;

    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        for (auto u : adj[x]) {
            if (visited[u]) {
                continue;
            }
            visited[u] = true;
            prev[u] = x;
            q.push(u);
        }
    }
    if (!visited[t]) {
        cout << -1 << endl;
    } else {
        int curr = t;

        vector<int> nodes;
        while (curr != s) {
            if (curr < n) {
                nodes.push_back(curr);
            }
            curr = prev[curr];
        }
        nodes.push_back(s);
        reverse(nodes.begin(), nodes.end());
        cout << nodes.size() << endl;
        for (auto x : nodes) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
