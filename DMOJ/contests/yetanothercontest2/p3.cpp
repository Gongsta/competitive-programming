#include <bits/stdc++.h>

using namespace std;

// This can work by finding the common prime factors, and then dividing by those common prime factors?
map<int, int> count_n;
map<int, set<int> > distinct;

int INF = 1 << 30;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K, h;

    cin >> N >> K;
    
    /* Steps
    1. Get prime factorization of all the elements, store it inside a list of vectors
    2. Remove the common factor of at least K elements until you are no longer able to.
    */
   int temp;
   for (int idx=1; idx<=N;idx++){
       cin >> h;
       temp = h;
       int count_temp = 0;

       while (temp % 2 == 0) {
           count_temp += 1;
           temp = temp/2;
           distinct[2].insert(idx);

            if (!count_n.count(2)) {
                count_n[2] = INF;
            }
            count_n[2] = min(count_n[2], count_temp);
       }
       // Get Prime factors
       for (int i=3; i<=sqrt(temp); i+=2) {
            bool success = false;
            count_temp = 0;
            if (temp == 1) {
                break;
            }
            while (temp % i == 0) {
                success = true;
                count_temp += 1;
                temp = temp / i;
                distinct[i].insert(idx);

           }
           if (success) {
            if (!count_n.count(i)) {
                count_n[i] = INF;
            }
            count_n[i] = min(count_n[i], count_temp);
           }
       }
       if (temp > 2) {
           if (!count_n.count(temp)) {
                count_n[temp] = 1;

           } else {
                count_n[temp] += 1;

           }
            distinct[temp].insert(idx);
           }

       }
    int total = 0;
    for (auto x: distinct) {
            // cout << x.first << ":" << x.second.size() << endl;
        if (x.second.size() >= K) {
            total += count_n[x.first];
        }
    }
   
   cout << total << endl;
    
    // for (auto x: count_n) {
    //     cout << x.first << ":" << x.second << endl;
    // }
    
    return 0;
}
