#include <bits/stdc++.h>

using namespace std;

int b_count_d[5000];

int prefix(int a, int b) {
    if (a == 0) {
        return b_count_d[b];
    } else {
        return b_count_d[b] - b_count_d[a-1];
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
        int arr[n];
        for (int i=0;i<n;i++) {
            cin >> arr[i];
            b_count_d[i] = 0;
        }

        for (int i=0;i<n;i++) {
            int b = arr[i];
            int count = 0;
            for (int j=i+1;j<n;j++) {
                int d = arr[j];
                if (b > d) {
                    count++;
                }
            }
            b_count_d[i] = count;
        }

        int total = 0;
        for (int c=0;c<n;c++) {
            for (int b=1;b<c;b++) {
                if (arr[b] > arr[c]) {
                    b_count_d[b]--;
                }
            }
        }

        for (int i=1;i<n;i++) { // Made this a prefix array
            b_count_d[i] += b_count_d[i-1];
        }
        for (int c=0;c<n;c++) {
            for (int a=0;a<c;a++) {
                if (arr[a] < arr[c]) {
                    if (c -a > 1) {
                        total += prefix(a+1,c-1);
                    }
                }
            }
        }
        cout << total << endl;
    }

    return 0;
}
