#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t,n;
    cin >> t;
    // Answers
    // If >=1 odd number, answer = # of even numbers
    // If even numbers only, find the minimal amount of operations to make an even number odd. 
    // Answer = (even Numbers - 1) + (minimum # of operations to make even number odd)
    int a;
    while (t--) {
        int even = 0;
        int odd = 0;
        int min_even_ops = 1 << 30;
        cin >> n;
        while (n--) {
            cin >> a;
            if (a % 2 == 0) {
                even++;
                if (odd == 0) {
                    int ops = 0;
                    while (a % 2 == 0) {
                        ops++;
                        a/=2;
                    }
                    min_even_ops = min(ops, min_even_ops);
                }
            } else {
                odd++;
            }
        }
        if (odd >= 1) {
            cout << even << endl;
        } else {
            cout << even -1 + min_even_ops << endl;
        }

    }
    return 0;
}
