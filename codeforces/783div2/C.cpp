#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    long long int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    long long int min_moves = 1;
    min_moves = min_moves << 60;
    for (int i=0;i<n;i++) {
        long long int count = 0;
        long long int curr = 0;
        for (int j=i+1;j<n;j++) {
            if (arr[j] <= curr) {
                long long int times = curr / arr[j];
                count += times + 1;
                curr = arr[j] * (times + 1);
            } else {
                count++;
                curr = arr[j];
            }
        }
        curr = 0;
        for (int j=i-1;j>=0;j--) {
            if (arr[j] <= curr) {
                long long int times =curr / arr[j];
                count += times + 1;
                curr = arr[j] * (times + 1);
            } else {
                count++;
                curr = arr[j];
            }
        }
        min_moves = min(min_moves, count);
    }
    cout << min_moves << endl;
    

    return 0;
}
