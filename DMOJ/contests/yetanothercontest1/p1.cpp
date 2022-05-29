#include <bits/stdc++.h>

using namespace std;

long int a[1000001];
long int b[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int K;
    long int sum = 0;
    cin >> N >> K;
    
    for (int i=0;i<N; i++) {
        cin >> a[i];
    }
    
    for (int i=0;i<N; i++) {
        cin >> b[i];
    }
    
    sort(a, a+N);
    sort(b, b+N);

    for (int i=0;i<N-1; i++) {
        sum += (a[i] * b[i]);
        sum = sum % (long int)(1e9 +7);
    }
    while (K) {
        int temp;
        if (a[N-1] > b[N-1]) {
            temp = K - (a[N-1] - b[N-1]);
            if (temp < 0) {
                b[N-1] += K;
                K = 0;

            } else {
                K = temp;
                b[N-1] = a[N-1];
            }
        } else if (b[N-1] > a[N-1]) {
            temp = K - (b[N-1] - a[N-1]);
            if (temp < 0) {
                a[N-1] += K;
                K = 0;
            } else {
                K = temp;
                a[N-1] = b[N-1];
            }

        } else {
            if (K%2 == 0) {
                a[N-1] += K/2;
                b[N-1] += K/2;
            } else {
                a[N-1] += K/2 + 1;
                b[N-1] += K/2;
            }
            K = 0;
        }
    }
    sum += (a[N-1] * b[N-1]);
    sum = sum % (long int)(1e9 +7);
    cout << sum << endl;

    return 0;
}
