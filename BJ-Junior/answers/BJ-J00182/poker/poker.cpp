#include <bits/stdc++.h>
using namespace std;
int a[10][15];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    char s[55], s1[55];
    for(int i = 0; i < n; i++){
        cin >> s[i] >> s1[i];
        if(s[i] == 'D') ans = 1;
        else if(s[i] == 'C') ans = 2;
        else if(s[i] == 'H') ans = 3;
        else ans = 4;
        if(s1[i] >= '2' && s1[i] <= '9') a[ans][(s1[i]-'0')] = 1;
        else{
            if(s1[i] == 'A') a[ans][1] = 1;
            else if(s1[i] == 'T') a[ans][10] = 1;
            else if(s1[i] == 'J') a[ans][11] = 1;
            else if(s1[i] == 'Q') a[ans][12] = 1;
            else a[ans][13] = 1;
        }
    }
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 13; j++)
            sum += a[i][j];
    cout << 52 - sum << endl;
    return 0;
}