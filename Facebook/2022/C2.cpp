#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> subset;
vector<string> ans0;
vector<string> ans1;
string s;

void search0(int k) {
    if (k == 10) {
        string new_s = "----------";
        for (auto sub: subset) {
            new_s[sub] = '.';
        }
        ans0.push_back(new_s);
    } else {
        search0(k+1);
        subset.push_back(k);
        search0(k+1);
        subset.pop_back();
    }
}

void search1(int k) {
    if (k == 9) {
        string new_s = "---------";
        for (auto sub: subset) {
            new_s[sub] = '.';
        }
        ans1.push_back(new_s);
    } else {
        search1(k+1);
        subset.push_back(k);
        search1(k+1);
        subset.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    search0(0);
    subset.clear();
    search1(0);
    for (int t=1;t<=tt;t++) {
        int n;
        cin >> n;
        cin >> s;
        cout << "Case #" << t << ":" << endl;
        int j = 0;
        for (int i=0;i<n-1;i++) {
            if (s.length() % 2 == 0) {
                cout << ans1[i] << endl;
            } else {
                cout << ans0[i] << endl;
            }
        }
    }

    return 0;
}
