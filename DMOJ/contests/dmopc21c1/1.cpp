#include <bits/stdc++.h>

using namespace std;

/*
2 1 2 2 -> Duke
//1 4 1 -> Alice
// 1 1 1 2 -> Alice 3 vs 1
// 3 3 3 4 -> Alice
// 1 1 2 2 -> Alice
// 1 1 10 Duke
// if # of odd >= # of even numbers, alice wins. No wait. Count total

*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long int a_count = 0;
    long int d_count = 0;
    
    long int N, x;
    
    cin >> N;
    while (N--) {
        cin >> x;
        if (x % 2 == 0) {
            d_count += x/2;
        } else {
            a_count += (x+1)/2;
        }
    }
    if (a_count >= d_count) {
        cout << "Alice"<< endl;
    } else {
        cout << "Duke" << endl;
    }

    return 0;
}
