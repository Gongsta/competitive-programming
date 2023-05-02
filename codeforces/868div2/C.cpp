#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

map<int, int> m;

void count_num_prime_factors(int num) {
    for (int d=2;d*d<=num;d++) {
        while (num % d == 0) {
            num /= d;
            m[d]++;
        }
    }
    if (num > 0) {
        m[num]++;
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
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        // To get the number of factors, you do the prime factorization, and count
        // the number of factors
        // There are unique factors, and then there's total number of factors, which are different
        
        // 4 vs 6 both have 2 prime factors. 
        // So you greedily try to square those numbers
        

        ll total_factors = 0;
        m.clear();
        for (int i=0;i<n;i++) {
            count_num_prime_factors(a[i]);
        }
        int left_over = 0;
        for (auto key: m) {
            total_factors += key.second / 2;
            left_over += key.second % 2;
        }

        total_factors += left_over / 3;
        cout << total_factors << endl;
        

        

    }

    return 0;
}
