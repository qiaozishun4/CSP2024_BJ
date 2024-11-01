#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool f[5][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;int a;
        cin>>s;
        if(s[1]=='A') a=1;
        if(s[1]>'1'&&s[1]<='9') a=s[1]-'0';
        if(s[1]=='T') a=10;
        if(s[1]=='J') a=11;
        if(s[1]=='Q') a=12;
        if(s[1]=='K') a=13;
        if(s[0]=='D') f[1][a]=1;
        if(s[0]=='C') f[2][a]=1;
        if(s[0]=='H') f[3][a]=1;
        if(s[0]=='S') f[4][a]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!f[i][j]) ans++;
        }
    }
    cout<<ans;
    return 0;
}
