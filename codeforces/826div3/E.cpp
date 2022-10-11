#include <vector>
#include <iostream>

typedef long long ll;

using namespace std;

int n;
ll b[200001];
vector<pair<int, int>> segments;

bool search(int elem_i, int seg_i) { // elem_i == end
    if (elem_i == n-1) return true;
    if (elem_i >= n) return false;

    int ending = seg_i;
    for (int j=seg_i+1;j<segments.size();j++) { // Consider all cases with the same starting
        if (segments[j].first != segments[seg_i].first) {
            break;
        }
        ending = j;
    }
    bool works = false;
    for (int i=seg_i;i<=ending;i++) {
        int start = segments[i].first;
        int end = segments[i].second;
        for (int j=ending+1;j<segments.size();j++) {
            if (segments[j].first != elem_i + 1) {
                break;
            } else {
                end = segments[j].second;
                works |= search(end, j+1);
                if (works) {
                    return true;
                }
            }
        }
    }
    return works;
}
// This is a merge intervals question.
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> b[i];
        }
        segments.clear();
        bool works = false;
        for (int i=0;i<n;i++) {
            if (b[i] + i < n) {
                segments.push_back({i, i+b[i]});
            }
        }

        for (int i=n-1;i>=0;i--) {
            if (i - b[i] >= 0) {
                segments.push_back({i - b[i], i});
            }
        }
        sort(segments.begin(), segments.end());
        if (segments.empty()) {
            works =false;
        } else {
            works = search(-1, 0);
        }
        
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
