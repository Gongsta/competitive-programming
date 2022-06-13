#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        bool works = true;
        /*
        Insight: a has to be in front of b
        b has to be in front of c
        */
       vector<int> s_b_pos;
       vector<int> t_b_pos;
       vector<int> s_c_pos;
       vector<int> t_c_pos;
        for (int i=0;i<n;i++) {
            if (s[i] == 'b') {
                s_b_pos.push_back(i);
            } else if (s[i] == 'c') {
                s_c_pos.push_back(i);
            }
            if (t[i] == 'b') {
                t_b_pos.push_back(i);
            } else if (t[i] == 'c') {
                t_c_pos.push_back(i);
            }
        }
        
        if (s_b_pos.size() != t_b_pos.size()) {
            works = false;
        }
        if (s_c_pos.size() != t_c_pos.size()) {
            works = false;
        }
        
        for (int i=0;i<s_c_pos.size();i++) {
            if (s_c_pos[i] == t_c_pos[i]) continue;
            if (s_c_pos[i] < t_c_pos[i]) {
                works = false;
                break;
            } else {
                for (int j=t_c_pos[i];j<s_c_pos[i];j++) {
                    if (s[j] == 'a') {
                        works = false;
                        break;
                    }             
                }
                
                if (works) {
                    for (int l=0;l<s_b_pos.size();l++) { // Update the b positions
                        if (s_b_pos[l] >= t_c_pos[i] && s_b_pos[l] < s_c_pos[i]) {
                            s_b_pos[l]++;
                        }
                        if (s_b_pos[l] > s_c_pos[i]) {
                            break;
                        }
                    }
                }
            }
        }
        for (int i=0;i<s_b_pos.size();i++) {
            if (s_b_pos[i] == t_b_pos[i]) continue;
            if (s_b_pos[i] < t_b_pos[i]) {
                works = false;
                break;
            } else {
                for (int j=t_b_pos[i];j<s_b_pos[i];j++) {
                    if (s[j] == 'c') {
                        works = false;
                        break;
                    }             
                }
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
