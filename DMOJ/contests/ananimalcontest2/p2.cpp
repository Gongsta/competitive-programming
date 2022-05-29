#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int arr[N];
    
    for (int i =0; i<N;i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+N);
    int med = N / 2;

    return 0;
}
