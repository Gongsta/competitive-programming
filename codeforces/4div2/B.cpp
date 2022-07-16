#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int d, sumT;
    cin >> d >> sumT;
    vector<pair<int, int>> v;
    for (int i=0;i<d;i++) {
        int minT,maxT;
        cin >> minT >> maxT;
        v.push_back({minT, maxT});
    }
    int max_total = 0;
    int min_total = 0;
    for (int i=0;i<d;i++) {
        max_total += v[i].second;
        min_total += v[i].first;
    }
    if (max_total < sumT || min_total > sumT) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int curr_total = min_total;
        vector<int> final;
        for (auto x: v) {
            final.push_back(x.first);
        }
        while (curr_total < sumT) {
            for (int i=0;i<d;i++) {
                if (final[i] < v[i].second) {
                    curr_total++;
                    final[i]++;
                    break;
                }
            }
        }
        for (int i=0;i<final.size();i++) {
            cout << final[i];
            if (i == final.size()-1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
        
        
    }


    return 0;
}
