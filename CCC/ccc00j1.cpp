#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int F,d;
    cin >> F >> d;
    cout << "Sun Mon Tue Wed Thr Fri Sat" << endl;
    for (int j=1;j<F;j++) {
        cout << "    ";
    }
    for (int i=1; i<=d;i++) {
        if (i<10) {
            cout << "  ";
        } else {
            cout << " ";
        }
        cout << i;
        if (i != d && (F + i - 1) % 7 != 0) {
            cout << " ";
        }
        if ((F + i - 1) % 7 == 0) {
            cout << endl;
        }
    }
    if ((F + d - 1) % 7 != 0) {
        cout << endl;
    }
    return 0;
}
