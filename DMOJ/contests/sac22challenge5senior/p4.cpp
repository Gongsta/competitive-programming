#include <bits/stdc++.h>

using namespace std;
map<int, bool> arr_pos; // bool -> start 
map<int, bool> arr_neg;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int N, Q;
	int l,r;
	cin >> N >> Q;
	while (N--) {
		cin >> l >> r;
		

		for (int i=l; i<=r; i++) {
			if (i<0) {
				i = -i;
			if (arr_neg[i] == 0) {
				arr_neg[i] = 1;
			}
			} else {
				if (arr_pos[i] == 0) {
					arr_pos[i] = 1;
				}

			}
		}

	}
	bool Y = true;
	while (Q--) {
		Y = true;

		cin >> l >> r;
		for (int i=l; i<=r; i++) {
			if (i<0) {
				i = -i;
			if (arr_neg[i] == 0) {
				Y = false;
				break;
			}
			} else {
				if (arr_pos[i] == 0) {
					Y = false;
					break;
				}
			}
		}
		if (Y) {
			cout << "Y\n";
		} else {
			cout << "N\n";
		}
	}
	
    return 0;
}
