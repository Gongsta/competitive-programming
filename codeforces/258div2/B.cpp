#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "yes" << endl;
        cout << "1 1" << endl;
    } else {
        bool works =true;
        int decreasing_count = 0;
        int l = 0;
        int r = 0;
        bool decreasing = false;
        for (int i=1;i<n;i++) {
            if (a[i] < a[i-1]) {
                if (!decreasing) {
                    l = i-1;
                    decreasing_count++;
                    decreasing = true;
                }
            } else if (a[i] > a[i-1]) {
                if (decreasing) {
                    r = i-1;
                    decreasing = false;
                    if (a[l] > a[i]) {
                        works = false;
                        break;
                    }
                }
            }
            if (decreasing && i == n -1) {
                r = i;
            }
            if (decreasing_count > 1) {
                works = false;
                break;
            }
        }
        if (l > 0) {
            if (a[r] < a[l-1]) {
                works = false;
            }
        }
        if (works) {
            cout << "yes" << endl;
            cout << l + 1 << " " << r + 1 << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
