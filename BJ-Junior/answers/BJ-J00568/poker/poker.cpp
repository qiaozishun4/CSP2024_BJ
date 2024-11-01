#include<bits/stdc++.h>
using namespace std;
bool vis[20][10];

int num(char c)
{
    if(c>='0'&&c<='9')
    {
        return c-'0';
    }
    else
    {
        if(c=='A') return 1;
        if(c=='T') return 10;
        if(c=='J') return 11;
        if(c=='Q') return 12;
        if(c=='K') return 13;
    }
    return 0;
}
int color(char c)
{
    if(c=='D') return 1;
    if(c=='C') return 2;
    if(c=='H') return 3;
    if(c=='S') return 4;
    return 0;
}

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        vis[num(s[1])][color(s[0])]=1;
    }
    int cnt=0;
    for(int i=1;i<=13;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(vis[i][j]==0) cnt++;
        }

    }
    cout<<cnt;
    return 0;
}
