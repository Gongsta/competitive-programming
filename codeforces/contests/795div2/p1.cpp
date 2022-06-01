#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int a, n;
    while (t--) {
        int odd = 0;
        int even = 0;
        
        cin >> n;
        
        while (n--) {
            cin >> a;
            if (a % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        cout << min(even, odd) << endl;
    

    }
    return 0;
}
