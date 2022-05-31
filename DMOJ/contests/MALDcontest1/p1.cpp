#include <bits/stdc++.h>

using namespace std;

bool containsyubo(string s) {
    if (s.find("yubo") != string::npos) {
       return true; 
    } else {
        return false;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    bool prev_is_yubo = false;
    bool counted = false;
    int count = 0;
    int N;
    cin >> N;
    string s;
    for (int i=0; i<N; i++) {
        cin >> s;
        if (prev_is_yubo) {
            count++;
        }
        if (containsyubo(s)) {
            if (!prev_is_yubo) {
                count += 1;
            }
            prev_is_yubo = true;
        } else {
            prev_is_yubo = false;
        }
    }
    
    

    return 0;
}
