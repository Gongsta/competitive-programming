#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
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
        int A = 0;
        int B = 0;
        int C = 0;
        int D = 0;
        for (char c: s) {
            if (c == 'A') {
                A += 1;
                A = min(A, n);
            } else if (c == 'B') {
                B += 1;
                B = min(B, n);
            } else if (c == 'C') {
                C += 1;
                C = min(C, n);
            } else if (c == 'D') {
                D += 1;
                D = min(D, n);
            }
        }
        cout << A + B + C + D << endl;
    }

    return 0;
}
