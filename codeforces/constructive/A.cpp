#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    while (n--) {
        if (n % 4 == 0 || n % 4 == 1) {
            cout << 'a';
        } else {
            cout << 'b';
        }
    }
    cout << endl;

    return 0;
}
