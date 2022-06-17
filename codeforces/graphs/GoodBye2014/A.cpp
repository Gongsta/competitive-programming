#include <bits/stdc++.h>

using namespace std;

int adj[30000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n, t;
	cin >> n >> t;
	for (int i=1;i<=n-1;i++) {
		cin >> adj[i];
	}
	int i = 1;
	while (i < t) {
		i = adj[i] + i;
	}
	if (i == t) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}


    return 0;
}
