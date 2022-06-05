#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, string>,vector<pair<int, string> >,  greater<pair<int, string> >> pq;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int R,S, D;
    string name;
    while (N--) {
        cin >> name >> R >> S >> D;
        pq.push({-(2* R + 3* S + D), name});
    }

    int counter = 0;
    while (!pq.empty()) {
        counter++;
        string n = pq.top().second;
        pq.pop();
        cout << n << endl;
        if (counter == 2) {
            break;
        }
    }
    return 0;
}
