#include<bits/stdc++.h>
using namespace std;
int n,sum;
bool vis[5][20];
string s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        int f;
        if(s[0]=='D')
        {
            f = 1;
        }
        else if(s[0]=='C')
        {
            f = 2;
        }
        else if(s[0]=='H')
        {
            f = 3;
        }
        else if(s[0]=='S')
        {
            f = 4;
        }
        if(s[1]=='A')
        {
            vis[f][1] = 1;
        }
        else if(s[1]=='T')
        {
            vis[f][10] = 1;
        }
        else if(s[1]=='J')
        {
            vis[f][11] = 1;
        }
        else if(s[1]=='Q')
        {
            vis[f][12] = 1;
        }
        else if(s[1]=='K')
        {
            vis[f][13] = 1;
        }
        else
        {
            vis[f][s[1]-'0'] = 1;
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(vis[i][j]==0)
            {
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}