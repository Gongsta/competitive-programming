#include <bits/stdc++.h>

using namespace std;

set<int, greater<int> > freegates;
set<int, greater<int> >::iterator it;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int G, P;
    
    cin >> G >> P;
    /* Intuition
    1. Store values of plane limits in an array
    2. Sort the array
    3. +1 if arr[i] >= arr, else this plane won't fit.
    */
   
   // Error in understanding: You have to assign them right away, much easier than I thought...
    
    int count = 0;
    int i;
    bool terminate = false;
    for (int k=G;k>=1; k--) {
        freegates.insert(k);
    }
    for (int j=1;j<=P; j++) {
        cin >> i;
        if (!terminate) {
            if (i > G) {
                i = G;
            }
            if (freegates.count(i)) {
                freegates.erase(i);
                count += 1;
            } else {
                bool found = false;
                it = freegates.upper_bound(i);
                if (it != freegates.end()) {
                    found = true;
                    count++;
                }
                if (!found) {
                    terminate = true;
                } else {
                    freegates.erase(it);
                }
            }
        }
    }
    cout << count << endl;
    
    return 0;
}