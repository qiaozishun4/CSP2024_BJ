#include <bits/stdc++.h>
using namespace std;
string a;
int t,n,m,k,x,y,d;
int ans[1005][1005],cnt;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cnt=0;
        memset(ans,0,sizeof(ans));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        ans[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            for(int j=0;j<m;j++)
            {
                if(a[j]=='x')
                {
                    ans[i][j+1]=2;
                }
            }
        }
        for(int i=1;i<=k;i++)
        {
            if(d==0)
            {
                if(ans[x][y+1]<2&&x>0&&x<=n&&y+1>0&&y+1<=m)
                {
                    y++;
                    ans[x][y]=1;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==1)
            {
                if(ans[x+1][y]<2&&x+1>0&&x+1<=n&&y>0&&y<=m)
                {
                    x++;
                    ans[x][y]=1;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==2)
            {
                if(ans[x][y-1]<2&&x>0&&x<=n&&y-1>0&&y-1<=m)
                {
                    y--;
                    ans[x][y]=1;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else
            {
                if(ans[x-1][y]<2&&x-1>0&&x-1<=n&&y>0&&y<=m)
                {
                    x--;
                    ans[x][y]=1;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(ans[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        cout<<cnt;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}