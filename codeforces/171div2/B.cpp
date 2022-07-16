#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int a[100000];

int prefix(int l, int r) {
    if (l == 0) {
        return a[r];
    } else {
        return a[r] - a[l-1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,t;
    cin >> n >> t;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        if (i != 0) {
            a[i] += a[i-1];
        }
    }
    int l = 0;
    int r = 0;
    int max_books = 0;
    while (l < n && r < n) {
        if (prefix(l,r) <= t) {
            max_books = max(max_books, r-l+1);
            r++;
        } else {
            l++;
        }
        if (l > r) {
            r = l;
        }
    }
    cout << max_books << endl;
  

    return 0;
}
