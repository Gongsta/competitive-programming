// NOT OPTIMIZED
#include <bits/stdc++.h>

using namespace std;

long int arr[1000001];
int main() {
    int T, N;
    cin >> T;
    arr[0] = 1;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 2;
    while (T--) {
        cin >> N;
        for (int i=4; i<=N; i++) {
			arr[i] = (i-1) * (arr[i-1] + arr[i-2]);
			arr[i] = arr[i] % (1000000007);
        }
        cout << arr[N] << "\n";
    }
    return 0;
}