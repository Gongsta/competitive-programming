#include <bits/stdc++.h>

using namespace std;

string S;
string substring = "";
int N;
int scores[1000];
void search(int k) {
    if (k==N) {
        check_substring

    } else {
        search(k+1);
        substring.push_back(S[k]);
        search(k+1);
        substring.pop_back();

    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> N >> S;
    
    

    return 0;
}
