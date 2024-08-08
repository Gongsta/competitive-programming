#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        vector<int> b;
        int next_val = -1;
        int next[n];
        int dist[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == -1) {
                next[i] = next_val;
            } else {
                next_val = a[i];
            }
        }
        int distance = 0;
        int first_num_idx = -1;
        int last_num_idx = n;
        for (int i = 0; i < n; i++) {
            if (a[i] != -1) {
                if (first_num_idx == -1) {
                    first_num_idx = i;
                }
                dist[i - distance] = distance;
                distance = 1;
                last_num_idx = i;
            } else {
                distance++;
            }
        }
        if (last_num_idx == n) {
            last_num_idx = 0;
            a[0] = 1;
        }

        for (int i = last_num_idx + 1; i < n; i++) {
            if (a[i - 1] / 2 < 1) {
                a[i] = a[i - 1] * 2;
            } else {
                a[i] = a[i - 1] / 2;
            }
        }
        for (int i = first_num_idx - 1; i >= 0; i--) {
            if (a[i + 1] / 2 < 1) {
                a[i] = a[i + 1] * 2;
            } else {
                a[i] = a[i + 1] / 2;
            }
        }

        bool works = true;
        int i = 0;
        while (i < n) {
            // cout << i << " " << a[i] << endl;
            if (a[i] != -1) {
                b.push_back(a[i]);
            } else {
                // TODO: handle sides
                // Could also be full of -1s, so many edge cases...
                int start = a[i - 1];
                int end = next[i];
                int min_intervals = 0;
                bool reversed = false;
                if (start < end) {
                    swap(start, end);  // todo fix logic
                    reversed = true;
                }
                vector<int> local_ans;
                while (start > end) {
                    start /= 2;
                    min_intervals++;
                    local_ans.push_back(start);
                }
                // Now, end is smaller than start. You can try reducing
                vector<int> end_queue;
                while (end != start) {
                    if (start > end) {
                        start /= 2;
                        local_ans.push_back(start);
                    } else {
                        end /= 2;
                        end_queue.push_back(end);
                    }
                }
                reverse(end_queue.begin(), end_queue.end());

                if (dist[i - 1] < local_ans.size() || (dist[i - 1] - local_ans.size()) % 2 != 0) {
                    cout << "not works" << i << " " << dist[i - 1] << " " << local_ans.size() << endl;
                    works = false;
                    break;
                }
                for (int j = 0; j < dist[i - 1] - local_ans.size(); j++) {
                    if (j % 2 == 0) {
                        local_ans.push_back(local_ans.back() * 2);
                    } else {
                        local_ans.push_back(local_ans.back() / 2);
                    }
                }
                local_ans.insert(local_ans.end(), end_queue.begin(), end_queue.end());
                i = (i - 1) + dist[i - 1] - 1;
                if (reversed) {
                    reverse(local_ans.begin(), local_ans.end());
                }
                for (auto v : local_ans) {
                    b.push_back(v);
                }
            }
            i++;
        }
        // Check the created array
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != a[i + 1] / 2 && a[i] / 2 != a[i + 1]) {
                works = false;
            }
            break;
        }
        if (works) {
            for (auto x : b) {
                cout << x << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
