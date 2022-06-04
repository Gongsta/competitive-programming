#include <bits/stdc++.h>

using namespace std;

int arr[100];
int main() {
    int N;
    cin >> N;
    
    for (int i=0;i<N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    for (int i=0;i<N; i++) {
        cout << arr[i] << endl;
    }
    return 0;

}