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
    int count = 0;
    int pos = 0;
    for (int i=1;i<n;i++) {
        if (a[i] < a[i-1]) {
            count++;
            pos = i;
            if (count >= 2) {
                break;
            }
        }
    }

    if (count >= 2) {
        cout << -1 << endl;
        
    } else {

    }
    return 0;
}
