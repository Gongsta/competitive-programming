#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    ll a[N];
    ll mod =1e9+7; 
    for (int i=0;i<N;i++) {
        cin >> a[i];
    }
    ll sum = 0;
    ll times = 1;
    for (int i=0;i<N-1;i++) {
        times *= 2;
        times %= mod;

    }
    for (int i=0;i<N;i++) {
        sum += a[i] * times;
        sum %= mod;
    }
    cout << sum << endl;
    

    return 0;
}
