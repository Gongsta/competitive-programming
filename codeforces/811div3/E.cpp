#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    set<int> s3;
    int i = 3;
    while (i <= 100) {
        s3.insert(i);
        i += i % 10;
    }

    while (t--) {
        bool has_five = false;
        bool has_other = false;
        bool has_one = false;
        bool has_three = false;
        int n;
        cin >> n;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
            if (a[i] % 5 == 0) {
                has_five = true;
            } else {
                has_other = true;
            }
        }
        if (has_five && has_other) {
            cout << "NO" << endl;
        } else if (has_five) {
            for (int i=0;i<n;i++) {
                if (a[i] % 10 == 5) {
                    a[i] += 5;
                }
            }
            bool works = true;
            for (int i=1;i<n;i++) {
                if (a[i] != a[i-1]) {
                    works = false;
                    break;
                }
            }
            if (works) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            for (int i=0;i<n;i++) {
                a[i] = a[i] % 20;
                while (a[i]% 10 == 1 || a[i] % 10 == 3 || a[i] % 10 == 7 || a[i] % 10 == 9) {
                    a[i] += a[i] % 10;
                }
                if (s3.count(a[i])) {
                    has_three = true;
                } else {
                    has_one = true;
                }
            }
            if (has_one && has_three) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
            
        }
        


    }

    return 0;
}
