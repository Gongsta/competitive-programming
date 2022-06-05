#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    int s, f;
    int total = 0;
    cin >> N;
    int n = N;
    while (n--) {
        cin >> s >> f;
        if (s * 5 - 3 * f > 40) {
            total++;
        }
    }
    if (total == N) {
        cout << total << "+" << endl;
    } else {
        cout << total << endl;
    }
    return 0;
}