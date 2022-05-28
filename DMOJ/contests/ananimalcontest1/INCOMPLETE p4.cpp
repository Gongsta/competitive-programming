#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,Q;
    cin >> N >> Q;
    
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    int l,r,x;
    
    bool found;
    while (Q--) {
        found = false;
        cin >> l >> r >> x;
        int a[r-l + 1];
        copy(arr+l,arr+r+1,a);
        sort(a, a+(r-l+ 1));
        int l1, r1;
        l1 = 0;
        r1 = r-l;
        found = false;
        while (r1>= l1) {
            if (a[l1] * a[r1] == x && a[l1] != a[r1]) {
                cout << "YES\n";
                found = true;
                break;
            } else {
                if (a[l1] * a[r1] > x) {
                    r1 -=1;
                } else {
                    l1 += 1;
                }
            }

        }
        if (!found) {
            cout << "NO\n";
        }
    }

    return 0;
}
