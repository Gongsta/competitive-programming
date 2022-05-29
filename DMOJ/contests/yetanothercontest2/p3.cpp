#include <bits/stdc++.h>

using namespace std;

// This can work by finding the common prime factors, and then dividing by those common prime factors?
map<int, int> count_n;
map<int, set<int>> distinct;

int INF = numeric_limits<int>::max();

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
   while (N--) {
       cin >> h;
       temp = h;
       int count_temp = 0;

       while (temp % 2 == 0) {
           count_temp += 1;
           temp = temp/2;
           distinct[2].insert(h);
       }
       if (!count_n.at(2)) {
           count_n[2] = INF;
       }
       count_n[2] = min(count_n[2], count_temp);
       // Get Prime factors
       for (int i=3; i<=sqrt(h); i+=2) {
            bool success = false;
            count_temp = 0;
            while (h % i == 0) {
                success = true;
                count_temp += 1;
                temp = temp / i;
                distinct[i].insert(h);

           }
           if (success) {
            if (!count_n.at(i)) {
                count_n[i] = INF;
            }
            count_n[i] = min(count_n[i], count_temp);
           }
       }
   }
   
   int total = 0;
   for (auto x: distinct) {
       if (x.second.size() >= K) {
           total += count_n[x.first];
       }
   }
   
   cout << total << endl;
    
    
    return 0;
}
