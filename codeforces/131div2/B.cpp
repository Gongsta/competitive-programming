#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

/*
Observation 1: Number must end with a 0
Maximize sum of numbers such that it is still divisble by 3
*/


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a, a+n, greater<int>());
    int sum = 0;
    for (int i=0;i<n;i++) {
        sum += a[i];
    }
    int i = n - 1;
    if (sum % 3 == 1) {
        sum -= a[i];
        i--;
        if (i < 0) {
            break;
        }
    }
    if (i < 0 || a[n-1] != 0) { 
        cout << -1 << endl;

    } else {
        string final;
        for (int j=0;j<i+1;j++) {
            final += '0' + a[j];
        }
        for (int j=i+1;j<n;j++) {
            if (a[j] == 0) {
                final += '0';
            }
        }
        cout << final << endl;

    }



    return 0;
}
