// This is totally a variation of the coin problem!
// We can't always act greedily, because it's not like the European coins!

// We use dynamic programming
#include <bits/stdc++.h>

using namespace std;

int dp[5281] = {10000}; // We use dynamic programming to solve, initialize to super big value
// Each value of dp represents the minimum amount of hits to reach it.
vector<int> clubs;

int INF = 1 << 30;
int main() {
	
	int d, n;
	cin >> d;
	cin >> n;
	int val;
	while (n--) {
		cin >> val;
		clubs.push_back(val);
	}
	
	dp[0] = 0;
	for (int i=1; i<=d; i++) {
		int temp = INF;
		for (int club: clubs) {
			if (i - club >= 0) {
				temp = min(dp[i-club] + 1, temp);
			}
		}
		dp[i] = temp;
	}
	if (dp[d] == INF) {
		cout << "Roberta acknowledges defeat." << endl;
	} else {
		cout << "Roberta wins in " << dp[d] << " strokes."  << endl;
	}

	return 0;
}