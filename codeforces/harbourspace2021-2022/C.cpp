#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int max_dp_one[11];
int max_dp_two[11];
int min_dp_one[11];
int min_dp_two[11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int score = 10;
        for (int j=0;j<s.length();j++) {
            int i = j+1;
            if (j % 2 == 1)  {
                if (s[j] == '1') {
                    max_dp_two[i] = max_dp_two[i-1] + 1;
                    min_dp_two[i] = min_dp_two[i-1] + 1;

                } else if (s[j] == '0') {
                    min_dp_two[i] = min_dp_two[i-1];
                    max_dp_two[i] = max_dp_two[i-1];

                } else {
                    min_dp_two[i] = min_dp_two[i-1];
                    max_dp_two[i] = max_dp_two[i-1] + 1;
                }
                
                min_dp_one[i] = min_dp_one[i-1];
                max_dp_one[i] = max_dp_one[i-1];
            } else {
                if (s[j] == '1') {
                    max_dp_one[i] = max_dp_one[i-1] + 1;
                    min_dp_one[i] = min_dp_one[i-1] + 1;

                } else if (s[j] == '0') {
                    min_dp_one[i] = min_dp_one[i-1];
                    max_dp_one[i] = max_dp_one[i-1];

                } else {
                    min_dp_one[i] = min_dp_one[i-1];
                    max_dp_one[i] = max_dp_one[i-1] + 1;
                }
                min_dp_two[i] = min_dp_two[i-1];
                max_dp_two[i] = max_dp_two[i-1];
            }
            if ((5 - (i+1)/2) + min_dp_one[i] < max_dp_two[i] || (5 - (i)/2) + min_dp_two[i] < max_dp_one[i]) {
                score = i;
                break;
            }
        }
        cout << score << endl;

    }

    return 0;
}
