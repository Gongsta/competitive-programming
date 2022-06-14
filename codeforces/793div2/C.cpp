#include <bits/stdc++.h>

using namespace std;

/*
Consider the case 1 1 3 3
You can optimal make it 1 3 3 1 so that beauty = 4

1. Sort it
2. If see duplicate, store is into a queue. Total count is that value.
3. Check duplicates in queue and remove those,

*/
int arr[200000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        unordered_set<int> s;
        int curr = 1;
        for (int i=1;i<n;i++) {
            if (arr[i] == arr[i-1]) {
                s.insert(arr[i]);
            } else {
                if (curr < n/2) {
                    curr++;
                } else {
                    s.insert(arr[i]);
                }
            }
        }
        int x = s.size();
        cout << min(x, curr) << endl;
        

    }

    return 0;
}
