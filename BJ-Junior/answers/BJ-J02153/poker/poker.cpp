#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    bool cd[5][15] = {};
    string s;
    cin>> n;
    for(int i=1;i<=n;i++){
        cin>> s;
        if(s[0] == 'C'){
            if(s[1] == 'T') cd[1][10] = true;
            else if(s[1] == 'J') cd[1][11] = true;
            else if(s[1] == 'Q') cd[1][12] = true;
            else if(s[1] == 'K') cd[1][13] = true;
            else if(s[1] == 'A') cd[1][1] = true;
            else cd[1][s[1]-'0'] = true;
        }
        if(s[0] == 'D'){
            if(s[1] == 'T') cd[2][10] = true;
            else if(s[1] == 'J') cd[2][11] = true;
            else if(s[1] == 'Q') cd[2][12] = true;
            else if(s[1] == 'K') cd[2][13] = true;
            else if(s[1] == 'A') cd[2][1] = true;
            else cd[2][s[1]-'0'] = true;
        }
        if(s[0] == 'H'){
            if(s[1] == 'T') cd[3][10] = true;
            else if(s[1] == 'J') cd[3][11] = true;
            else if(s[1] == 'Q') cd[3][12] = true;
            else if(s[1] == 'K') cd[3][13] = true;
            else if(s[1] == 'A') cd[3][1] = true;
            else cd[3][s[1]-'0'] = true;
        }
        if(s[0] == 'S'){
            if(s[1] == 'T') cd[4][10] = true;
            else if(s[1] == 'J') cd[4][11] = true;
            else if(s[1] == 'Q') cd[4][12] = true;
            else if(s[1] == 'K') cd[4][13] = true;
            else if(s[1] == 'A') cd[4][1] = true;
            else cd[4][s[1]-'0'] = true;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!cd[i][j]) ans++;
        }
    }
    cout<< ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}