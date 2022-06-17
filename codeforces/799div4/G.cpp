#include <bits/stdc++.h>

using namespace std;

/*
Observation: If it breaks in one sequence, it will break in the other sequence. 

So store for each i as a boolean that represents whether arr[i] * 2 > arr[i-1]
And then loop over the array and count the number of sequences. 
*/
int arr[200000];
bool dp[200000];
int seq[200000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        dp[0] = true;
        for (int i=1;i<n;i++) {
            dp[i] = (arr[i] * 2 > arr[i-1]) ? true : false;
        }
        // Store longest sequence
        seq[0] = 1;
        for (int i=1;i<n;i++) {
            if (dp[i]) {
                seq[i] = seq[i-1] + 1;
            } else {
                seq[i] = 1;
            }
        }
        int count = 0;
        for (int i=0;i<n;i++) {
            if (seq[i] > k) {
                count++;
            }
        }
        cout << count << endl;


    }

    return 0;
}
