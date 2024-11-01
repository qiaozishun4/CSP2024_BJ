#include<bits/stdc++.h>
using namespace std;
bool a[4][13];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        int x,y;
        cin>>s;
        if(s[0]=='D') x=0;
        else if(s[0]=='C') x=1;
        else if(s[0]=='H') x=2;
        else if(s[0]=='S') x=3;
        if(s[1]>='2'&&s[1]<='9') y=s[1]-'0'-1;
        else if(s[1]=='A') y=0;
        else if(s[1]=='T') y=9;
        else if(s[1]=='J') y=10;
        else if(s[1]=='Q') y=11;
        else if(s[1]=='K') y=12;
        a[x][y]=1;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(a[i][j]==0) ans++;
        }
    }
    cout<<ans;
    return 0;
}
