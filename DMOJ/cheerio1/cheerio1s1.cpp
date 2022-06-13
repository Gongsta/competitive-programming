
#include <bits/stdc++.h>

using namespace std;
// 37 + 15 = 52
int main()
{
    int N,D;
    cin >> N >> D;
    int p,r,g;
    long long int total_time = 0;
    int curr = 0;
    while (N--) {
        cin >> p >> r >> g;
        total_time += p - curr;
        if (total_time < r) {
            total_time = r;
        } else if (total_time - (r+g) >=0) {
            int t = total_time % (r+g);
            if (t > r) {
                // you don't have to wait
                t = 0;
            } else {
                // you have to wait r - t seconds
                total_time += r - t;
            }
        }
        
        curr = p;
    }
    total_time += D - curr;
    cout << total_time << endl;

    return 0;
}