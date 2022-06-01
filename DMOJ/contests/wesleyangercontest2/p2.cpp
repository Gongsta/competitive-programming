#include <bits/stdc++.h>

// Getting errors
using namespace std;
priority_queue<pair<int, int> > pq;
unordered_set<int> days;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int N,M,Q;
    cin >> N >> M >> Q;
    
    long long int d, p;
    long long int total = 0;

    long long int curr_d_best_price;

    Q--;
    cin >> d >> p;

    pq.push({-p, d});
    long long int num_c_purchased = 0;

    bool no_choice = false;
    long long prev_d, prev_p;
    if (d < M) {
        num_c_purchased = M-d;
        total += (1000000 * num_c_purchased);
        no_choice = true;
        prev_d = d;
        prev_p = p;
    }
    while (Q--) {
        cin >> d >> p;
        if (!no_choice) {
            pq.push({-p, d});
        } else {
            if (prev_d = d) {
                prev_p = max(prev_p, p);

            } else {
                total += (prev_d - d) * prev_p;
                prev_d = d;
                prev_p = p;
            }

            if (Q == 0) {
                total += prev_p * prev_d;
            }

        }
    }
    
    if (!no_choice) {
        while (num_c_purchased < M) {
            int p = -pq.top().first; int d = pq.top().second;
            pq.pop();
            if (!days.count(d)) {
                total += p;
                days.insert(d);
                num_c_purchased++;
            }
            if (num_c_purchased < M) {
                if ((d-1 > 0) && !days.count(d-1)) {
                    total += p;
                    days.insert(d-1);
                    num_c_purchased++;
                }
            }

        }
    }
    cout << total << endl;
    
    

    return 0;
}
