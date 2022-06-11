#include <bits/stdc++.h>

using namespace std;

/*
I came up with the topological sort solution, when really I could have come up with something simpler. 

I think to practice, you need to get better at visualizing and understanding.

OMG, I did not realize the array was in a non-decreasing order, which makes solving the problem much easier.
I was getting TLE...
*/
int arr[100000];
int final[100000];
unordered_map<int, vector<int> > m;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        m.clear();
        int l = 1;
        int r = 1;
        for (int i=1;i<=n;i++) {
            final[i] = i;
        }
        int count = 0;
        bool works = true;
        for (int i=1;i<=n;i++) {
            cin >> arr[i];
            if (arr[i] != arr[i-1] && i > 1) {
                if (count == 1 || i == n) {
                    works = false;
                } else { // Perform rotation
                    rotate(final+l,final+l+1,final+l+count);
                    l = i;
                    count = 1;
                }
            } else {
                count++;
                if (i == n) {
                    if (count == 1) {
                        works = false;
                    } else { // Perform rotation
                        rotate(final+l,final+l+1, final+l+count);
                    }
                }

            }
        }
        if (n == 1) {
            works = false;
        }

        if (works) {
            for (int i=1;i<=n;i++) {
                cout << final[i];
                if (i == n) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
