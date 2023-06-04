#include <bits/stdc++.h>

typedef long long ll;

using namespace std;




/*
Notice that if the last bit is a 1, then this string is impossible to construct
If we always put in position i-1, then 
- 0-th bit is gonna be flipped n times
- 1-th bit is gonna be flipped n-1 times

I think we deconstruct it in reverse, where we try to find a way to get the previous string
without having a 1 as the last bit


[1, 0] is from p = 1


100110
so p = 5
01100
so p = 4
1001 impossible
so p = 3
1000
011
always keep the 1st in the front

p = 2
01110
p = 4
1000
p = 2
010
p = 0
10
p = 1
0
p = 0

two different sequences prepduct ce the same

How to create 100110:
0
00
110
0110
00110
100110


*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        if (a[n-1] == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            int cum_sum = 0;
            for (int i=n-1;i>=0;i--) {
                if (i!= 0 && a[i] == 1 && a[i-1] == 0) {
                    cout << cum_sum;
                    cum_sum = 0;
                } else if (i != 0 && a[i-1] == 1) {
                    cout << 0;
                    cum_sum++;
                } else if (i == 0 && a[i] == 1) {
                    cout << cum_sum;
                } else {
                    cout << 0;
                }
                if (i != 0) {
                    cout << " ";
                } else {
                    cout << endl;
                }
            }
        }
    }

    return 0;
}
