#include<bits/stdc++.h>
using namespace std;
bool p[10][20];
int ans=0;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        cin>>a>>b;
        int x=0,y=0;
        if(a=='D') x=1;
        if(a=='C') x=2;
        if(a=='H') x=3;
        if(a=='S') x=4;
        if(b=='A') y=1;
        if(b=='2') y=2;
        if(b=='3') y=3;
        if(b=='4') y=4;
        if(b=='5') y=5;
        if(b=='6') y=6;
        if(b=='7') y=7;
        if(b=='8') y=8;
        if(b=='9') y=9;
        if(b=='T') y=10;
        if(b=='J') y=11;
        if(b=='Q') y=12;
        if(b=='K') y=13;
        p[x][y]=1;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(!p[i][j])
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
