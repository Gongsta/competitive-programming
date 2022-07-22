#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int a,b,c;
        int arr[4];
        cin >> a >> b >> c;
        arr[1] = a;
        arr[2] = b;
        arr[3] = c;
        bool works = false;
        int cnt = 0;
        while (x != 0 && cnt < 3) {
            x = arr[x];
            cnt++;
        }
        if (cnt != 3) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }


    }

    return 0;
}
