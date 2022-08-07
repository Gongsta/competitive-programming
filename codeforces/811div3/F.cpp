#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,d12,d23,d31;
        bool works = true;
        cin >> n >> d12 >> d23 >> d31;
        int curr = 4;
        if (d12 + d23 == d31) { // configuration 1
             if (d12 - 1 + d23 - 1 < n - 3) {
                works = false;
             } else {
                if ()

             }
            
        } else if (d31 + d23 == d12) { // Conf 2
             if (d31 - 1 + d23 - 1 < n - 3) {
                works = false;
             } else {

             }

        } else { // Conf 3
            if (d12 - 1 + d31 - 1 < n - 3) {
                works = false;
            } else {

            }

        }
        if (works) {
            cout << "YES" << endl;
            

        } else {
            cout << "NO" << endl;
        }
        

    }

    return 0;
}
