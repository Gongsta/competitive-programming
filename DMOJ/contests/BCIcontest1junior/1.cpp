#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int count = 0;
    while (n--) {
        string s;
        cin >> s;
        if (s == "face") {
            count++;
        }
    }
    cout << count << endl;


    return 0;
}
