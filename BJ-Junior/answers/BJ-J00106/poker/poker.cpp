#include <bits/stdc++.h>
using namespace std;
int n;
int f[5][20];
int cnt=52;
int check(string c){
    if(c[1]=='A'){
        return 1;
    }
    if(c[1]=='T'){
        return 10;
    }
    if(c[1]=='J'){
        return 11;
    }
    if(c[1]=='Q'){
        return 12;
    }
    if(c[1]=='K'){
        return 13;
    }
    return c[1]-'0';
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(s[0]=='D'){
            int t=check(s);
            if(f[1][t]==0){
                f[1][t]=1;
                cnt--;
            }
        }
        if(s[0]=='C'){
            int t=check(s);
            if(f[2][t]==0){
                f[2][t]=1;
                cnt--;
            }
        }
        if(s[0]=='H'){
            int t=check(s);
            if(f[3][t]==0){
                f[3][t]=1;
                cnt--;
            }
        }
        if(s[0]=='S'){
            int t=check(s);
            if(f[4][t]==0){
                f[4][t]=1;
                cnt--;
            }
        }
    }
    cout<<cnt;
    return 0;
}
