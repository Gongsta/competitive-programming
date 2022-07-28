#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    ll a[N];
    map<int, int> m;
    for (int i=0;i<N;i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    sort(a, a+N);
    int start = 0;
    while (a[start] == 0) {
        start++;
    }
    int val = a[start];
    for (int i=start+1;i<N;i++) {
        val = gcd(val, a[i]);
    }
    cout << val << endl;

    return 0;
}
