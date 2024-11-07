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
        char vowels[5];
        vowels[0] = 'a';
        vowels[1] = 'e';
        vowels[2] = 'i';
        vowels[3] = 'o';
        vowels[4] = 'u';
        for (int i = 0; i < 5; i++) {
            if (i < n % 5) {
                for (int j = 0; j < n / 5 + 1; j++) {
                    cout << vowels[i];
                }
            } else {
                for (int j = 0; j < n / 5; j++) {
                    cout << vowels[i];
                }
            }
        }
        cout << endl;
    }

    return 0;
}
