// NOT DONE
#include <bits/stdc++.h>

using namespace std;

map<string, set<string> > must;
map<string, set<string> > cant;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int X;
    cin >> X;
    
    int violations = 0;
    string a,b,c;
    while (X--) {
        cin >> a >> b;
        must[a].insert(b);

    }
    int Y;
    cin >> Y;
    while (Y--) {
        cin >> a >> b;
        cant[a].insert(b);

    }
    int G;
    cin >> G;
    while (G--) {
        cin >> a >> b >> c;
        if (must.count(a)) {
            if (!must[a].count(b) && !must[a].count(c)) {
                violations++;
            }
        } 
        if (must.count(b)) {
            if (!must[b].count(a) && !must[b].count(c)) {
                violations++;
            }
        } 
        if (must.count(c)) {
            if (!must[c].count(a) && !must[c].count(b)) {
                violations++;
            }
        } 
        
        if (cant.count(a)) {
            if (cant[a].count(b) || cant[a].count(c)) {
                violations++;
            }
        } 
        if (cant.count(b)) {
            if (cant[b].count(a) || cant[b].count(c)) {
                violations++;
            }
        } 

        if (cant.count(c)) {
            if (cant[c].count(a) || cant[c].count(b)) {
                violations++;
            }
        } 
        
    }
    cout << violations << endl;
    return 0;
}
