#include <bits/stdc++.h>

using namespace std;

multiset<int> s;
int main() {
	int T, N, c;
	cin >> T;
	cin >> N;
	while (N--) {
		cin >> c;
		s.insert(c);
	}
	
	int total = 0;
	
	for (auto i: s) {
		T -= i;
		if (T >= 0) {
			total += 1;
		} else {
			break;
		}
	}
	cout << total << endl;
    return 0;
}
