#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> modified_a;
vector<int> modified_b;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        ll a[n];
        ll sum_a = 0;
        ll sum_b = 0;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            sum_a += a[i];
        }
        int k;
        cin >> k;
        ll b[k];
        for (int i=0;i<k;i++) {
            cin >> b[i];
            sum_b += b[i];
        }
        bool works = true;

        if (sum_a != sum_b) {
            works = false;
        }
        modified_a.clear();
        modified_b.clear();
        for (int i=0;i<n;i++) {
            if (a[i] % m != 0) {
                if (modified_a.empty() || a[i] != modified_a.back()) {
                    modified_a.push_back(a[i]);
                }
            } else {
                int temp = a[i];
                while (temp % m == 0) {
                    temp /= m;
                }
                if (modified_a.empty() || temp != modified_a.back()) {
                    modified_a.push_back(temp);
                }
            }
        }

        for (int i=0;i<k;i++) {
            if (b[i] % m != 0) {
                if (modified_b.empty() || b[i] != modified_b.back()) {
                    modified_b.push_back(b[i]);
                }
            } else {
                int temp = b[i];
                while (temp % m == 0) {
                    temp /= m;
                }
                if (modified_b.empty() || temp != modified_b.back()) {
                    modified_b.push_back(temp);
                }
            }
        }

        if (modified_b.size() != modified_a.size()) {
            works = false;
        } else {
            for (int i=0;i<modified_a.size();i++) {
                if (modified_a[i] != modified_b[i]) {
                    works = false;
                    break;
                }
            }

        }
        if (works){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
