#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int u,v,t,d;
    cin >> u >> v >> t >> d;
    int arr1[t];
    int arr2[t];
    arr1[0] = u;
    arr2[t-1] = v;
    for (int i=1;i<t;i++) {
        arr1[i] = arr1[i-1] + d;
    }
    arr1[t-1] = v;
    for (int i=t-2;i>=0;i--) {
        arr2[i] = arr2[i+1] + d;
    }
    arr2[0] = u;
    int total = arr1[0];
    bool using_one = true;
    // 5 7 9 11
    // 5 14 12 10
    
    // 5 7 9 3
    // 5 7 5 3
    
    // 10 12 14 4
    // 10 8 6 4
    

    for (int i=1;i<t;i++) {
        if (abs(arr1[i] - v) > d * (t-i-1)) {
            total += arr2[i];
        }
        else if (abs(arr2[i] - u) > d * i) {
            total += arr1[i];
        } else {
            total += max(arr1[i], arr2[i]);
        }
    }
    cout << total << endl;

    return 0;
}
