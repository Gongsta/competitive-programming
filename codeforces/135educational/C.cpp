#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int get_digits(ll x) {
    int digits = 0;
    while (x > 0) {
        x /= 10;
        digits++;
    }
    return digits;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        priority_queue<int> a;
        priority_queue<int> b;
        int x;
        for (int i=0;i<n;i++) {
            cin >> x;
            a.push(x);
        }
        for (int i=0;i<n;i++) {
            cin >> x;
            b.push(x);
        }
        int total = 0;
        while (!a.empty()) {
            int a_top = a.top(); a.pop();
            int b_top = b.top(); b.pop();
            if (a_top == b_top) {
                continue;
            } else if (a_top > b_top) {
                total++;
                a.push(get_digits(a_top));
                b.push(b_top);
            } else {
                total++;
                b.push(get_digits(b_top));
                a.push(a_top);
            }
        }
        cout << total << endl;
 
    }

    return 0;
}
