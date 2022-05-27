#include <bits/stdc++.h>

using namespace std;

int arr[20001] = {0};
int total_count[20001];
char last[20001];
char first[20001];


int count_duplicates(string word) {
    int num = 0;
    for (int i=0; i< word.length() - 1; i++) {
        if (word[i] == word[i+1]) {
            num++;
        }
    }
    return num;
}

int main() {
    int N;
    string word;
    
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> word;
        first[i] = word[0];
        last[i] = word[word.length()-1];
        total_count[i] = count_duplicates(word);
        
        int max_val = 0;
        for (int j=0; j<i; j++) {
            max_val = max(max_val, arr[j] + total_count[i] + (last[j] ==  first[i]));
        }
        arr[i] = max_val;
    }
    
    cout << arr[N] << "\n";

    return 0;
}
