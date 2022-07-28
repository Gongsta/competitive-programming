#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    ll a[N];
    for (int i=0;i<N;i++) {
        cin >> a[i];
    }
    bool works = true;
    for (int i=0;i<N;i++) {
        if (a[i] > i+1) {
            works = false;
            break;
        }
    }
    

    return 0;
}
