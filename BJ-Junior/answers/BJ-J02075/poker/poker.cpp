#include<bits/stdc++.h>
using namespace std;
int n,c[10][60],h,s,cnt;
char pk[60][5];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>pk[i];
        if(pk[i][0]=='D') h=1;
        else if(pk[i][0]=='C') h=2;
        else if(pk[i][0]=='H') h=3;
        else if(pk[i][0]=='S') h=4;
        if(pk[i][1]=='T') s=10;
        else if(pk[i][1]=='J') s=11;
        else if(pk[i][1]=='Q') s=12;
        else if(pk[i][1]=='K') s=13;
        else if(pk[i][1]=='A') s=1;
        else s=pk[i][1]-48;
        c[h][s]=1;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(c[i][j]==0) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}