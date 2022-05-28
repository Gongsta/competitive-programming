#include <bits/stdc++.h>

using namespace std;

set<int> adj[20001];
set<int> visited;
queue<int> q;
int main() {
	int N, a, b;
	cin >> N;
	
	for (int i=1; i<=N; i++) {
		cin >> a;
		while (a--) {
			cin >> b;
			adj[i].insert(b);
		}
		if (adj[i].empty()) {
			q.push(i);
			visited.insert(i);
		}
	}
	
	bool clean;
	while (q.size() < N) {
		for (int i=1; i<=N; i++) {
			clean = true;
			if (!visited.count(i)) {
				for (auto u: adj[i]) {
					if (!visited.count(u)) {
						clean = false;
					}
				}

				if (clean) {
					visited.insert(i);
					q.push(i);
				}
			}
		}
	}
	
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	
	return 0;
}