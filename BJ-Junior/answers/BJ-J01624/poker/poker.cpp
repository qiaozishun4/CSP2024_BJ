#include<bits/stdc++.h>
using namespace std;
int n, ans = 0;
bool a[5][15];//C D H S
int main (){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 0;i<n;i++){
        string s;
        cin >> s;
        int x, y;
        if(s[0] == 'C') x = 1;
        else if(s[0] == 'D') x = 2;
        else if(s[0] == 'H') x = 3;
        else x = 4;
        if(s[1] == 'T') y = 10;
        else if(s[1] == 'J') y = 11;
        else if(s[1] == 'Q') y = 12;
        else if(s[1] == 'K') y = 13;
        else if(s[1] == 'A') y = 1;
        else y = s[1]-'0';
        a[x][y] = true;
    }
    for(int i = 1;i<=4;i++){
        for(int j = 1;j<=13;j++){
            if(!a[i][j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
//1
