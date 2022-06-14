#include <bits/stdc++.h>

using namespace std;

int arr[1000];
int final[1000];
unordered_map<int, int> m;
// Attempted but failed, I think this one can also be brute forced. 
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n ==1) {
            cout << -1 << endl;
        } else {
            for (int i=0;i<n;i++) {
                cin >> arr[i];
                final[i] = arr[i];
                if (m.count(arr[i])) {
                    m[arr[i]]++;
                } else {
                    m[arr[i]] = 1;
                }
            }
            bool fail = false;
            for (auto x: m) {
                if (x.second > n/2) {
                    fail = true;
                    break;
                }
            }
            if (fail) {
                cout << -1 << endl;
            } else {
                sort(final, final+n);
                for (int i=0; i<n;i++) {
                    if (final[i] != arr[i]) continue;
                    int j = i+1;
                    if (j == n) {
                        swap(arr[0], arr[i]); // Swap first and last element
                    } else {
                        while (final[j] == arr[i]) {
                            j++;
                        }
                        swap(final[i], final[j]);
                        
                    }
                    
                }
                for (int i=0;i<n;i++) {
                    cout << final[i];
                    if (i != n-1) {
                        cout << " ";
                    } else {
                        cout << endl;
                    }
                }
            
                
            }
        }
    }

    return 0;
}
