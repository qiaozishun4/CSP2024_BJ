#include<bits/stdc++.h>
using namespace std;
bool box[10][20];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        int hs, ds;
        if(s[0] == 'D') hs = 1;
        if(s[0] == 'C') hs = 2;
        if(s[0] == 'H') hs = 3;
        if(s[0] == 'S') hs = 4;
        ds = s[1] - '0';
        if(s[1] == 'A') ds = 1;
        if(s[1] == 'T') ds = 10;
        if(s[1] == 'J') ds = 11;
        if(s[1] == 'Q') ds = 12;
        if(s[1] == 'K') ds = 13;
        box[hs][ds] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 13; j++){
            if(!box[i][j]){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}