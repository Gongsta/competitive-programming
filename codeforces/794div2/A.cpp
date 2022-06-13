#include <bits/stdc++.h>

using namespace std;

// I actually had no idea for this one...which is embarassing considering this is an 800 problem..
// Solution -> brute force implementation
int arr[50];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int t;
	cin >> t;
	int n;
	while (t--) {
		cin >> n;
		for (int i=0;i<n;i++) {
			cin >> arr[i];
		}
		int sum = 0;
		for (int i=0;i<n;i++) {
			sum += arr[i];
		}
		bool works = false;
		for (int i=0;i<n;i++) {
			int temp_sum = sum;
			temp_sum -= arr[i];
			if ((float) temp_sum / (n-1.0) == arr[i]) {
				works = true;
				break;
			}
		}
		if (works) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}
    return 0;
}
