#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    
    cin >> N >> K;
    for (int i=0; i<N;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    
    long int total = 0;
    while (K > 0) {
        total += arr[N-K];
        K--;
    }
    
    cout << total << endl;
    return 0;
}
