#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long ans=1;
    long long n,m,k,x,y,d;
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    char c[n][m];
    for(long long i=0;i<n;i++)
        for(long long j=0;j<m;j++)
            cin>>c[i][j];
    for(long long i=1;i<=k;i++)
    {
        if(d==0)
        {
            if(c[x][y+1]=='.'&&x<=n&&x>=0&&y+1>=0&&y+1<=m)
            {
                y++;
                ans++;
            }
            else
            {
                d=(d+1)%4;
            }
            continue;
        }
        if(d==1)
        {
            if(c[x+1][y]=='.'&&x+1<=n&&x+1>=0&&y>=0&&y<=m)
            {
                x++;
                ans++;
            }
            else
            {
                d=(d+1)%4;
            }
            continue;
        }
        if(d==2)
        {
            if(c[x][y-1]=='.'&&x<=n&&x>=0&&y-1>=0&&y-1<=m)
            {
                y--;
                ans++;
            }
            else
            {
                d=(d+1)%4;
            }
            continue;
        }
        if(d==3)
        {
            if(c[x-1][y]=='.'&&x-1<=n&&x-1>=0&&y>=0&&y<=m)
            {
                x--;
                ans++;
            }
            else
            {
                d=(d+1)%4;
            }
            continue;
        }
    }
    cout<<ans<<endl;
    return ;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}
