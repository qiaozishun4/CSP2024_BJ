#include<bits/stdc++.h>
using namespace std;
bool vis[4][15];
int change(char c)
{
    if(c=='A')return 1;
    if(c=='T')return 10;
    if(c=='J')return 11;
    if(c=='Q')return 12;
    if(c=='K')return 13;
    return c-'0';
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        int now;
        if(c=='D')now=0;
        if(c=='C')now=1;
        if(c=='H')now=2;
        if(c=='S')now=3;
        cin>>c;
        vis[now][change(c)]=1;
    }
    int cnt=0;
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<14;j++)
        {
            if(!vis[i][j])
            {
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
