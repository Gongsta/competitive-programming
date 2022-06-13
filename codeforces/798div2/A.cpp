#include <bits/stdc++.h>


using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n,m,k;
        string a, b;
        cin >> n >> m >> k;
        cin >> a >> b;
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        string final;
        int a_p = 0;
        int b_p = 0;
        int a_count = 0;
        int b_count = 0;
        
        while (a_p < n && b_p < m) {
            if (a_count == k) {
                final += b[b_p];
                b_p++;
                b_count++;
                a_count = 0;
                
                
            } else if (b_count == k) {
                final += a[a_p];
                a_p++;
                a_count++;
                b_count = 0;
            } else {
                if (a[a_p] < b[b_p]) {
                    final += a[a_p];
                    a_p++;
                    a_count++;
                    b_count = 0;
                    
                } else {
                    final += b[b_p];
                    b_p++;
                    b_count++;
                    a_count = 0;
                }
                
            }
        }
        cout << final << endl;
        
        
    }

    return 0;
}
