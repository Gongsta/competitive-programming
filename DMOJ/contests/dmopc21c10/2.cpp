#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int move(int curr, int i, int n) {
    i = curr + i;
    while (i < 0) {
        i+=n;
    }
    while (i >= n) {
        i -= n;
    }
    return i;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    int one_pos = -1;
    int two_pos = -1;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << endl;
    } else {
        map<int, int> m;
        int start = 0;
        for (int i=0;i<n-1;i++) {
            m[a[i]] = a[i+1];
        }
        m[a[n-1]] = a[0];
        int one_target = -1;
        for (auto x: m) {
            if (x.second == x.first + 1 || (x.first == n && x.second == 1)) {
                continue;
            } else {
                one_target = x.first;
                break;
            }
        }
        if (one_target != -1) { // We can swap
            if (one_target == 1) {
                for (int i=0;i<n;i++) {
                    if (a[i] == one_target) {
                        one_pos = i;
                    } else if (a[i] == one_target + 1) {
                        two_pos = i;
                    }
                }
                // Option 1: Place one_pos right before two_pos
                int val_after_two_pos =  a[move(two_pos, 1, n)];
                int val_after_one_pos =  a[move(one_pos, 2, n)];
                if (val_after_one_pos == 2) {
                    val_after_one_pos =  a[move(one_pos, 1, n)];
                } 
                if (val_after_two_pos == 1) { // Case 3: We can swap one and two, or put one in front of two
                    // There are actually 3 ways to swap.
                    /*
                    1. Swap 1 and 2
                    2. Put 2 after 1
                    3. Put 1 in front of 2. 
                    */
                    // if (a[move(two_pos,-1, n)] < a[move(one_pos, 1,n)]) {
                    //     swap(a[move(two_pos,-1,n)], a[one_pos]);
                    // } else {
                    //     swap(a[one_pos], a[two_pos]);
                    // }
                } else {
                    if (val_after_one_pos < val_after_two_pos) { // Place two pos after one_pos
                        swap(a[move(one_pos, 1, n)], a[two_pos]);
                    }
                    else {  // Place one pos in front of two_pos
                        swap(a[one_pos], a[move(two_pos, -1, n)]);
                    }
                }
            } else {
                for (int i=0;i<n;i++) {
                    if (a[i] == one_target) {
                        one_pos = i;
                    } else if (a[i] == one_target + 1) {
                        two_pos = i;
                    }
                }
                swap(a[move(one_pos, 1, n)], a[two_pos]);
            }
        }
        for (int i=0;i<n;i++) {
            if (a[i] == 1) {
                start = i;
                break;
            }
        }
        if (start == 0) {
            for (int i=start;i<n;i++) {
                cout << a[i];
                if (i == n-1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }

        } else {
            for (int i=start;i<n;i++) {
                cout << a[i] << " ";
            }
            for (int i=0;i<start;i++) {
                cout << a[i];
                if (i == start - 1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }
    }

    return 0;
}