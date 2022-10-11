#include <iostream>

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
        if (n == 3) {
            cout << -1 << endl;
        }  else if (n ==2) {
            cout << "2 1" << endl;
        }
        else {
            cout << n << " " << n - 1 << " ";
            for (int i=1;i<n-1;i++) {
                cout << i;
                if (i == n-2) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }

    }

    return 0;
}
