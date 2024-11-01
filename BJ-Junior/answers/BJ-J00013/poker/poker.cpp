#include<bits/stdc++.h>
using namespace std;
int vis[11][101];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        int x,y;
        cin>>a>>b;
        if(a=='D')
            x=1;
        else if(a=='C')
            x=2;
        else if(a=='H')
            x=3;
        else
            x=4;
        if('0'<=b&&b<='9')
            y=b-'0';
        else if(b=='T')
            y=10;
        else if(b=='A')
            y=1;
        else if(b=='J')
            y=11;
        else if(b=='Q')
            y=12;
        else
            y=13;
        vis[x][y]=1;
    }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(vis[i][j]==0)
                ans++;
    cout<<ans<<endl;
    return 0;
}