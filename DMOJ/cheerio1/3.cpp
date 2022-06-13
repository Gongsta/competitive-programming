/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

char arr[1501][1501];
int main()
{
    int N;
    cin >> N;
    for (int i=1; i<=N;i++) {
        for (int j=1;j<=N;j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int j=1; j<=N;j++) {
        int count = 0;
        for (int i=1;i<=N;i++) {
            if (arr[i][j] == 'S') {
                count++;
            }
        }
        for (int i=N;i>=1;i--) {
            if (count > 0) {
                arr[i][j] = 'S';
            } else {
                arr[i][j] = '.';
            }
            count--;
        }
    }
    
    for (int i=1; i<=N;i++) {
        for (int j=1;j<=N;j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}