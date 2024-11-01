#include<bits/stdc++.h>
using namespace std;
int n,cnt;
char s[60][2];
bool f[5][14];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][0]>>s[i][1];
        int x,y;
        if(s[i][0]=='D')x=1;
        if(s[i][0]=='C')x=2;
        if(s[i][0]=='H')x=3;
        if(s[i][0]=='S')x=4;
        if(s[i][1]=='A')y=1;
        else if(s[i][1]=='T')y=10;
        else if(s[i][1]=='J')y=11;
        else if(s[i][1]=='Q')y=12;
        else y=13;
        f[x][y]=1;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(f[i][j]==0) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
