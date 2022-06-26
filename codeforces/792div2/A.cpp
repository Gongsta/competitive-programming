#include <bits/stdc++.h>


using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		if (num < 100) {
			cout << num % 10 << endl;
		} else {
			int min_num = num % 10;
			while (num > 0) {
				if (num % 10 < min_num) {
					min_num = num % 10;
				}
				num /= 10;
			}
			cout << min_num << endl;

		}
	}
	return 0;
}