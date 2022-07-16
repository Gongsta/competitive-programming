#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

/*
Idea: Store the number of times that you are ahead of someone.
If count for everyone is >=3, then this person is a winner.
*/

int a[50001][5];
bool visited[50001];

bool compare(int x, int y)  {
    int count = 0;
    for (int i=0;i<5;i++) {
        if (a[x][i] < a[y][i]) {
            count++;
        }
    }
    if (count >= 3) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            for (int j=0;j<5;j++) {
                cin >> a[i][j];
            }
        }
        int winner = 0;
        for (int i=1;i<n;i++) {
            if (!compare(winner, i)) {
                winner = i;
            }
        }
        bool works = true;
        for (int i=0;i<n;i++) {
            if (i != winner) {
                if (!compare(winner, i)) {
                    works = false;
                    break;
                }

            }
        }
        if (works){
            cout << winner + 1 << endl;
        } else {
            cout << -1 << endl;
        }

    }

    return 0;
}
