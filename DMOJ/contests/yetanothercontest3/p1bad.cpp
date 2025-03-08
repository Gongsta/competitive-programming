#include <bits/stdc++.h>

using namespace std;

// bitset<1000000001> bs;
vector<pair<int, int> > v;
deque<pair<int, int> > final_path;

int move_rock(int rock_pos, pair<int, int> swap_pair) {
    if (rock_pos == swap_pair.first) {
        rock_pos = swap_pair.second;
    } else if (rock_pos == swap_pair.second) {
        rock_pos = swap_pair.first;
    }
    return rock_pos;
}

// int M and int B (final position) are CONSTANTS
bool dfs(int swap_i, int rock_pos, int M, int B,vector< pair<int, int> > swap_permutations) {
    if (swap_i == M) { // Becuse last swap might also be -1, so we check the state of the one after that
        if (rock_pos == B) {
            return true;
        } else {
            return false;
        }
    }
    // If we don't know the swap,
    if (v[swap_i].first == -1) {
        int temp_rock_pos;
        for (auto swap_pair: swap_permutations) {
            temp_rock_pos = move_rock(rock_pos, swap_pair);
            final_path.push_back(swap_pair);
            // cout << "Pushing to final path:" << swap_pair.first << ":" << swap_pair.second << endl;
            if (!dfs(swap_i+1, temp_rock_pos, M, B,swap_permutations)) {
                final_path.pop_back();
                // cout << "Popping to final path:" << swap_pair.first << ":" << swap_pair.second << endl;
            } else {
                return true;
            }

        }

    } else { // We know the swap, so we can keep track of the position of the rock
        rock_pos = move_rock(rock_pos, v[swap_i]);  // Move the rock
        final_path.push_back(v[swap_i]);
        // cout << "Pushing to final path:" << "swap_i" << swap_i << v[swap_i].first << ":" << v[swap_i].second << endl;
        bool f = dfs(swap_i+1, rock_pos, M, B,swap_permutations);
        if(!f) {
            final_path.pop_back();
            // cout << "Popping to final path:" << "swap_i" << swap_i << v[swap_i].first << ":" << v[swap_i].second << endl;
        }
        return f;
    }
    // return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, A, B;
    pair<int, int> p;
    cin >> N >> M >> A >> B;
    int mm = M;
    while (mm--) {
        cin >> p.first;
        if (p.first == -1) {
            v.push_back(p);
        } else {
            cin >> p.second;
            if (p.second < p.first) {
                swap(p.first, p.second);
            }
            v.push_back(p);
        }
    }
    
    // Generate all the possible swap permutations
    vector< pair<int, int> > swap_permutations;
    pair<int, int> temp;
    for (int i=1; i<=N; i++) {
            temp.first = i;
            temp.second = B;
            if (temp.first > temp.second) {
                swap(temp.first, temp.second);
            }
            if (i != B) {
                swap_permutations.push_back(temp);
            }
    }

    for (int i=2; i<=N; i++) {
            temp.first = 1;
            temp.second = i;
            if (i != B) {
                swap_permutations.push_back(temp);
            }
    }
    dfs(0, A, M, B, swap_permutations);

    while (!final_path.empty()) {
        temp = final_path.front();
        final_path.pop_front();
        cout << temp.first << " " << temp.second << "\n";
    }
    return 0;
}
