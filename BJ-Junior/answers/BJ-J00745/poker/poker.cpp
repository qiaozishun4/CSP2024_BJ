#include<bits/stdc++.h>
using namespace std;
string s[55];
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, m = 52; cin >> n; 
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(s[i] == s[j]) {
                s[j] = "x";
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(s[i] != "x") m--;
    }
    cout << m << endl;
    return 0;
}