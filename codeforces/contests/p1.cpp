#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	long long int n;
	long long int min, max;
	long long int temp;
	
	long long int remainder;
	cin >> t;
	while (t--) {
		min = 0;
		max = 0;
		cin >> n;
		if (n == 0) {
			cout << "-1" << endl;
			continue;
		}
		temp = n;
		// Calculate maximum
		remainder =  temp % 4;
		max += temp / 4;
		if (remainder != 2 && remainder != 0) {
			cout << "-1" << endl;
			continue;
		} else if (remainder == 2) {
			if (max == 0) {
				cout << "-1" << endl;
				continue;
			}
		}
		//Calculate minimum
		temp = n;
		remainder  = temp % 6;
		min += temp / 6;

		if (remainder != 2 && remainder != 0 && remainder != 4) {
			cout << "-1" << endl;
			continue;
		} else if (remainder == 4) {
			min += 1;
		} else if (remainder == 2) {
			if (min == 0) {
				cout << "-1" << endl;
				continue;
			}
			min += 1;
		}

		
		cout << min << " " << max << endl;
	}

    return 0;
}
