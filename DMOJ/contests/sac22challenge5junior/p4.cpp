#include <bits/stdc++.h>

using namespace std;

void helper(int c, vector<int> f, map<int, vector<int>* >m) {
        if (m[c].size() == 0) {
            f.push_back(c);
        } else {
            for (auto course : m[c]) {
                if (m.at(course).size() == 0) {
                    f.push_back(course);
                } else {
                    int course_to_check;
                    course_to_check = m.at(course)->pop_back();
                    helper(course_to_check, f, m);
                }
            }
        }
}

int main() {
    map<int, vector<int>* > m;
    int N;
    cin >> N;
    int a, b;
    vector<int> f;
    int course_to_check;

    for (int i=1; i<=N; i++) {
        cin >> a;
        if (a !=0) {
            while (a--) {
                cin >> b;
                m.at(i)->insert(b);
            }
        }
    }
    for (auto c: m) {
        helper(c.first, f, m);
    }

    // Printing
    for (int i=0; i< f.size(); i++) {
        if (i == f.size() - 1) {
            printf("%d\n", f[i]);

        } else {
            printf("%d ", f[i]);
        }
        
    }
    return 0;
}
