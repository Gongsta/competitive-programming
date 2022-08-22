#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        map<int, int> m;
        int smallest = 1<< 30;
        int largest = -1;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            m[a[i]]++;
            smallest = min(smallest, a[i]);
            largest = max(largest, a[i]);
        }
        


        
        int second_smallest = smallest;
        for (auto x: m) {
            if (x.first == smallest) {
                continue;
            } else {
                second_smallest = x.first;
                break;
            }
        }
        

    }

    return 0;
}
