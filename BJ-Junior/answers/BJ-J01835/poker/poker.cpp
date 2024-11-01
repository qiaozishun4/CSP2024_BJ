#include<bits/stdc++.h>
using namespace std;
bool vis[4][13];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int x,y;
        if(s[0]=='D') x=0;
        if(s[0]=='C') x=1;
        if(s[0]=='H') x=2;
        if(s[0]=='S') x=3;
        if(s[1]=='A') y=0;
        if(s[1]=='2') y=1;
        if(s[1]=='3') y=2;
        if(s[1]=='4') y=3;
        if(s[1]=='5') y=4;
        if(s[1]=='6') y=5;
        if(s[1]=='7') y=6;
        if(s[1]=='8') y=7;
        if(s[1]=='9') y=8;
        if(s[1]=='T') y=9;
        if(s[1]=='J') y=10;
        if(s[1]=='Q') y=11;
        if(s[1]=='K') y=12;
        vis[x][y]=1;
    }
    int ans=0;
    for(int i=0;i<=3;i++)
    {
        for(int j=0;j<=12;j++)
        {
            if(vis[i][j]==0) ans++;
        }
    }
    cout<<ans;
    return 0;
}