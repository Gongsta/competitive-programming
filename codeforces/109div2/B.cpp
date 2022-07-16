#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    priority_queue<pair<int,int>> pq;
    while (n--) {
        int a,b;
        cin >> a >> b;
        pq.push({b,a});
    }
    int score = 0;
    int plays = 1;
    while (!pq.empty() && plays > 0) {
        plays--;
        plays += pq.top().first;
        score += pq.top().second;
        pq.pop();
    }
    cout << score << endl;

    return 0;
}
