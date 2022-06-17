// This is actually a super interesting problem! Make sure to write it down because it's really cool. I feel like I have seen similar ideas on youtube before. It 
// comes down to being a math problem
#include <bits/stdc++.h>

using namespace std;

int arr[200000];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        int total = 0;
        for (int i=0;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                if (arr[i] >= arr[j]) {
                    total++;
                }
            }
        }
        cout << total << endl;
        
        
    }

    return 0;
}
