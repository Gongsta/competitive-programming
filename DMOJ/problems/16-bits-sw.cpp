#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    long long int a,b, c;
    while (N--) {
        cin >> a >> b >> c;
        if (a * b == c) {
            cout << "POSSIBLE DOUBLE SIGMA\n";
        } else {
            cout << "16 BIT S/W ONLY\n";
        }
    }

    return 0;
}
