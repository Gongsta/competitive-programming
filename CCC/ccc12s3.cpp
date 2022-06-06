#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> m; // Mapping of reading -> frequency
// map<int, set<int> > m; // Mapping of frequency -> set of frequencies



/* Another much faster approach will be to store the frequencies, and sort those frequencies.
We then search for those frequencies, rather than constantly iterate.
*/
// I think this solution below will be too slow.
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, R;
    cin >> N;
    while (N--) {
        cin >> R;
        if (!m.count(R)) {
            m[R] = 1;
        } else {
            m[R]++;
        }
    }
    
    set<int> frequencies;
    for (auto x: m) {
        frequencies.insert(x.second);
    }
    
    if (frequencies.size() == 1) {
        cout << 0 << endl;
    }


    return 0;
}
