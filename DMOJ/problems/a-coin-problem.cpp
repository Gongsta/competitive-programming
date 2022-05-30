#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// Very similar problem in competitive programmer's handbook
// Recursive implementation
// int INF = numeric_limits<int>::max();
// vector<int> coins;

// unordered_map<int, int> m;

// int solve(int x, int l) {
//     if (m.count(x)) {
//         return m[x];
//     } else {
//         m[x] = INF;
//         for (int i=0;i<l; i++) {
//             int val;
//             if (x-coins[i] >= 0) {
//                 val = solve(x-coins[i], l);
//                 if (val != INF) { // Else overflow
//                     m[x] = min(m[x], val + 1);
//                 }
//             }
//         }
//         return m[x];
//     }
// }

// int main() {
//     int N, V;
//     cin >> N >> V;
    
//     int d;
//     while (N--) {
//         cin >> d;
//         coins.push_back(d);

//     }
//     int target, l;
//     while (V--) {
//         m.clear();
//         m[0] = 0;
//         cin >> target >> l;
//         solve(target, l);
        
//         if (m[target] == INF) {
//             cout << "-1\n";
//         } else {
//             cout << m[target] << "\n";
//         }


//     }
// }


// // Iterative solution seems too slow...
// EDIT: Recursive was also too slow...damn this problem is strict

vector<int> coins;
int value[100001];
int INF = numeric_limits<int>::max();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int N, V, d; 
    
    cin >> N >> V;
    while (N--) {
        cin >> d;
        coins.push_back(d);
    }
    
    int target,l;
    while (V--) {
        cin >> target >> l;
        value[0] = 0;
        
        for (int x=1; x<=target; x++) {
            value[x] = INF;
            for (int i=0; i<l; i++) {
                if (x-coins[i] >= 0) {
                    if (value[x-coins[i]] != INF) {
                        value[x] = min(value[x], value[x-coins[i]] + 1);
                    }
                }
            }
        }
        if (value[target] == INF) {
            printf("-1\n");
        } else {
            printf("%d\n", value[target]);
        }

    }

    return 0;
}
