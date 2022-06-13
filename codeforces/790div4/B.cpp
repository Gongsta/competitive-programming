#include <bits/stdc++.h>

using namespace std;

int arr[51];
int main()
{
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        int min_val = 1 << 30;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
            min_val = min(min_val, arr[i]);
        }
        int total = 0;
        for (int i=0;i<n;i++) {
            total += arr[i] - min_val;
        }
        cout << total << endl;
        
    }

    return 0;
}
