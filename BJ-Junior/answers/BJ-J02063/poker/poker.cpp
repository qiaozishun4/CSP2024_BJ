#include<bits/stdc++.h>
using namespace std;
int n;
bool s[7][15];
int ans;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        cin>>a>>b;
        int x,y;
        if(a=='D')x=1;
        if(a=='C')x=2;
        if(a=='H')x=3;
        if(a=='S')x=4;

        if(b=='A')y=1;
        else if(b=='T')y=10;
        else if(b=='J')y=11;
        else if(b=='Q')y=12;
        else if(b=='K')y=13;
        else y=int(b-'0');
        s[x][y]=1;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(s[i][j]==0)ans++;
        }
    }
    cout<<ans;
    return 0;
}
