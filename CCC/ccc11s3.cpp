#include <bits/stdc++.h>
using namespace std;

bool recursive_empty_check(int x_orig, int y_orig, int m) {
    int x = x_orig / pow(5, m-1);
    int y = y_orig / pow(5, m-1);
    if (y == 0) {
        if (x >= 1 && x <=3) {
            return false;
        }
    } else if (y == 1) {
        if (x == 2) {
            return false;
        } else if (x == 1){
            return recursive_empty_check(x_orig-pow(5,m-1), y_orig-pow(5,m-1), m-1);
        } else if (x == 3) {
            return recursive_empty_check(x_orig-3*pow(5,m-1),y_orig-pow(5,m-1), m-1);
        }
    } else if (y == 2) {
        return recursive_empty_check(x_orig-2*pow(5,m-1), y_orig-2*pow(5,m-1), m-1);
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    int m, x, y;
    bool empty;
    while (T--) {
        cin >> m >> x >> y;

        empty = recursive_empty_check(x,y,m);

        if (empty) {
            cout << "empty" << endl;
        } else {
            cout << "crystal" << endl;
        }
    }
    return 0;
}