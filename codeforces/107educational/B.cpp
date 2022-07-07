#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

/* IDEA: Generate a table with all the primes,
gcd is the largest prime of length c
y is a prime of length b
x is the product of gcd * y such that it has a length of a (c+b = a)

But I guess that doesn't work super well in certain circumstances.

*/



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 1000000000;
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    int min_val = 1;
    int min_val2 = 1;

    vector<int> digit_prime;
    vector<int> digit_prime2; // to use in case a ==b
    for (int i=2;i<n;i++) {
        if (prime[i] && (long long) i * i <= n) {
            if (i > min_val) {
                digit_prime.push_back(i);
                min_val *= 10;
            } 
            else if (i > min_val2) {
                digit_prime2.push_back(i);
                min_val2 *= 10;
            } 
            for (int j=i*i;j<=n;j+=i) {
                prime[i] = false;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int a,b,c;
        cin >> a >> b >> c;
        if (c == 1) { // Find two coprime numbers
            cout << digit_prime[a-1] << " " << digit_prime2[b-1] << endl;
        } else { // Make gcd(x,y) a prime with two digits
            int val = digit_prime[c-1];
            int min_a = pow(10, a-1);
            int min_b = pow(10, b-1);
            
            int val_a = val;
            int val_b = val;
            while (val_a < min_a) {
                val_a *= 10;
            }

            while (val_b < min_b)  {
                val_b *= 10;
            }
            if (val_a == val_b) {
                val_a += val;
            }
            cout << val_a << " " << val_b << endl;
        }

    }

    return 0;
}
