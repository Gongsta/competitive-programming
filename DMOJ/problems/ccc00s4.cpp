// This is totally a variation of the coin problem!
// We can't always act greedily, because it's not like the European coins!

// We use dynamic programming
#include <bits/stdc++.h>

using namespace std;

int dp[5281] = {10000}; // We use dynamic programming to solve, initialize to super big value
// Each value of dp represents the minimum amount of hits to reach it.
vector<int> clubs;
int main() {
	
	int d, n;
	cin >> d;
	cin >> n;
	int val;
	while (n--) {
		cin >> val;
		clubs.push_back(val);
	}

	return 0;
}