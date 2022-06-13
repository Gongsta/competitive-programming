/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,T;
    cin >> N >> T;
    string name;
    int p;
    cin >> name >> p;
    N--;
    int min_p = abs(T-p);
    int new_p;
    string new_name;
    while (N--) {
        cin >> new_name >> new_p;
        if (abs(T-new_p) < min_p) {
            name = new_name;
            min_p = abs(T-new_p);
        }
    }
    cout << name << endl;
        
    return 0;
}