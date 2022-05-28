#include <bits/stdc++.h>

using namespace std;

set<int> s;

int main() {
	int N,a;
	cin >> N;
	
	while (N--) {
		cin >> a;
		s.insert(a);
	}
	
	for (auto i: s) {
		cout << i << "\n";
	}
	
	return 0;
}