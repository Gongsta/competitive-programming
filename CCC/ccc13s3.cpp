#include <bits/stdc++.h>

using namespace std;

int arr[4][4];
/*
There are 6 different games being played, and in each game,
there are 3 different outcomes. 
- A wins and B loses
- A loses and B wins
- A and B both tie

We can do a complete search to see the end game state and how
many of those team a wins.
*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T,G;
    cin >> T >> G;
    int A,B,SA,SB;
    while (G--) {
        cin >> A >> B >> SA >> SB;
        A--;
        B--;
    }
    return 0;
}
