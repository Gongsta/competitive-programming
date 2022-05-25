#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    int count = 0;
    int curr_i = 0;
    string s;
    string temp1, temp, cache;
    cin >> N >> s;

    N--;
    for (int n=0; n< s.length() -1; n++) {
        if (s[n] == s[n + 1]) {
            count += 1;
        }
    }
    curr_i  = s.length() - 1;

    bool concat = true;
    while (N--) {
        concat = false;
//        cout << "curr_i = " << curr_i;
        cin >> temp1;
        if (cache != "") {
            if (cache.at(cache.length() - 1) == temp1[0]) {
                temp = s + cache + temp1;
            } else {
                cache = "";
                temp = s + temp1;

            }
        }
        if (temp[curr_i] == temp[curr_i + 1]) {
            s = temp;
            concat = true;
        } else {
            for (int n=0; n < temp.length() - s.length() -1; n++) {
                if (temp[n+curr_i+1] == temp[n+curr_i + 2]){
                    s = temp;
                    concat = true;
                    break;
                }
            }
            if (!concat) { // Store temporarily
                cache = temp1;
            }
        } 

        // Update count
        for (int n=curr_i; n<s.length() - 1; n++) {
            if (s[n] == s[n+1]){
                count += 1;
                // cout << n << s[n] << s[n+1] << endl;
            }
        }
        curr_i = s.length() - 1;

    }
    cout << count << endl;

    return 0;
}
