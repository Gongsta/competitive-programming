#include <iostream>

using namespace std;

string arr[50];

int dist(string a, string b) {
    int f = 0;
    for (int i=0;i<a.length();i++) {
        f += abs((int)a[i] - (int)b[i]);
    }
    return f;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        for (int i=0;i<n;i++){
            cin >> arr[i];
        }
        int final = 1 << 30;
        for (int i=0;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                final = min(dist(arr[i], arr[j]), final);
            }
        }
        cout << final << endl;
        
    }

    return 0;
}
