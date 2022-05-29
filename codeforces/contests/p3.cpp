#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> rows;
unordered_map<int, int> cols;
int main() {
    /* Queries
    1. Store in a map, one for rows and one for columns denoting the number of rooks. 
    2. Remove from the map
    3. Can be done diagonally? Na, it its square yes but not a vertical rectangle. But you can still
    try to move up diagonally
    */
   int n,q,t;
   cin >> n >> q;
   int a,b;
   int x1,x2,y1,y2;
   while (q--) {
        cin >> t;
        if (t == 1) {
            scanf("%d %d", &a, &b);
           if (!rows.count(a)) {
               rows[a] = 1;
            } else {
               rows[a] += 1;

            }
            if (!cols.count(b)) {
               cols[b] = 1;
            } else {
               cols[b] += 1;
            }
        } else if (t == 2) {
            scanf("%d %d", &a, &b);
           rows[a] -= 1;
           cols[b] -= 1;

       } else {
           bool not_attacked = true;
           scanf("%d %d %d %d", &x1,&y1,&x2,&y2);
            // cin >> x1 >> y1 >> x2 >> y2;
            for (int i=x1; i<=x2; i++)  {
                if (!rows.count(i) || rows[i] <= 0) {
                    for (int j=y1; j<=y2; j++) {
                     if (!cols.count(j) || cols[j] <= 0) {
                        not_attacked = false;
                        break;
                        }
                    }
                    break;
                }
            }
       if (not_attacked) {
           cout << "Yes\n";
       } else {
           cout << "No\n";
       }
       
       }
    }

    return 0;
}
