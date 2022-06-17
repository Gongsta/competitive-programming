#include <bits/stdc++.h>

using namespace std;

int arr[200000];
int prefix_sum(int a, int b) {
    if (a==0) {
        return arr[b];
    } else {
        return arr[b] - arr[a-1];
    }

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        long long int total = 0;
        int i=1;
        int prev = 0;
        while (i < n) {
            while (i<n && s[i] == s[prev]) {
                i++;
            }
            if (i == n) {
                break;
            }
            total += (i - prev) + total;
            prev = i;
            
        }
        cout << total + n << endl;

    }

    return 0;
}
