#include <bits/stdc++.h>

using namespace std;

long int INF = numeric_limits<long int>::max();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, P;
    string name;
    float M, CS, E;
    
    cin >> N >> P;
    long int score;
    pair<string, long int> low;
    low.second = INF;
    pair<string, long int> high;
    high.second = 0;
    while (N--) {
        cin >> name >> M >> CS >> E;
        score = floor(4.0 * sqrt(M) + 3.0 * pow(CS, P) - 4.0 * E);
        if (score < low.second) {
            low.second = score;
            low.first = name;
        }
        if (score > high.second) {
            high.second = score;
            high.first = name;
        }
    }
    cout << high.first << " " << high.second << endl;
    cout << low.first << " " << low.second << endl;
    return 0;
}
