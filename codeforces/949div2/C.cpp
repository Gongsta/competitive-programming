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

bool reachable(int a, int b) {
    if (a == 1 || a == b) {
        return true;
    }
    if (a > b) {
        return false;
    }
    return reachable(a, b / 2);
}
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

        // Fill out last numbers correctly
        for (int i = last_num_idx + 1; i < n; i++) {
            if (a[i - 1] / 2 < 1) {
                a[i] = a[i - 1] * 2;
            } else {
                a[i] = a[i - 1] / 2;
            }
        }
        // Fill out first few numbers correctly
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
            if (a[i] != -1) {
                b.push_back(a[i]);
            } else {
                int start = a[i - 1];
                int end = next[i];
                int min_intervals = 0;
                bool reversed = false;
                if (start > end) {
                    swap(start, end);
                    reversed = true;
                }
                // cout << start << " " << end << endl;
                vector<int> local_ans;
                while (!reachable(start, end)) {
                    start /= 2;
                    min_intervals++;
                    local_ans.push_back(start);
                }
                // we know start <= end
                vector<int> end_queue;
                while (start != end) {  // since we can reach start from end, there's the end
                    end /= 2;
                    min_intervals++;
                    end_queue.push_back(end);
                }
                if (!end_queue.empty()) {  // remove the last value, since its the same as in local_ans
                    end_queue.pop_back();
                    min_intervals--;
                }
                reverse(end_queue.begin(), end_queue.end());

                if (dist[i - 1] - 1 < min_intervals) {
                    // cout << "not works" << i << " " << dist[i - 1] << " " << local_ans.size() << endl;
                    works = false;
                    break;
                }
                for (int j = 0; j < dist[i - 1] - 1 - min_intervals; j++) {
                    if (j % 2 == 0) {
                        if (local_ans.empty()) {
                            local_ans.push_back(start * 2);
                        } else {
                            local_ans.push_back(local_ans.back() * 2);
                        }
                    } else {
                        local_ans.push_back(local_ans.back() / 2);
                    }
                }
                local_ans.insert(local_ans.end(), end_queue.begin(), end_queue.end());
                if (reversed) {
                    reverse(local_ans.begin(), local_ans.end());
                }
                for (auto v : local_ans) {
                    b.push_back(v);
                }
                i = (i - 1) + dist[i - 1] - 1;
            }
            i++;
        }

        // for (auto x : b) {
        //     cout << x << " ";
        // }
        // cout << endl;
        // Check the created array works
        for (int i = 0; i < n - 1; i++) {
            if (b[i] != b[i + 1] / 2 && b[i] / 2 != b[i + 1]) {
                works = false;
                break;
            }
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
