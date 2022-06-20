#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


ll prefix[100000];
ll calculate(int a, int b) {
    if (a == 0) {
        return prefix[b];
    } else {
        return prefix[b] - prefix[a-1];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k;
    cin >> n >> k;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }

    int t[n];
    for (int i=0;i<n;i++) {
        cin >> t[i];
    }
    ll total = 0;
    for (int i=0;i<n;i++) {
        if (t[i]) {
            total += a[i];
        } 
    }
    
    for (int i=0;i<n;i++) {
        if (i == 0) {
            if (!t[i]) {
                prefix[i] = a[i];
            } else {
                prefix[i] = 0;
            }
        } else {
            if (!t[i]) {
                prefix[i] = a[i] + prefix[i-1];
            } else {
                prefix[i] = prefix[i-1];
            }
        }
    }
    ll gain = 0;
    for (int i=k-1;i<n;i++) {
        gain = max(gain, calculate(i-k+1, i));
    }
    total += gain;
    cout << total << endl;

    return 0;
}
