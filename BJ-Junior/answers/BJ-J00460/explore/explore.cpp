#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,ans=1;
    cin>>T;
    int n,m,p,x,y,d;
    for(int i=1;i<=T;i++)
    {
        cin>>n>>m>>p;
        cin>>x>>y>>d;
        int ditu[n+2][m+2];
        char a;
        for(int j=0;j<=n+1;j++)
        {
            for(int k=0;k<=m+1;k++)
            {
                if(j==0 || j==n+1 || k==0 || k==m+1)
                {
                    ditu[j][k]=1;
                    continue;
                }
                cin>>a;
                if(a == 46)
                {
                    ditu[j][k]=0;
                }
                else
                {
                    ditu[j][k]=1;
                }
            }
        }
        for(int l=1;l<=p;l++)
        {
            if(d==0)
            {
                if(ditu[x][y+1]==0)
                {
                    ditu[x][y]=2;
                    y++;
                    ans++;
                }
                else if(ditu[x][y+1]==2)
                {
                    ditu[x][y]=2;
                    y++;
                }
                else
                {
                    d++;
                }
            }
            else if(d==1)
            {
                if(ditu[x+1][y]==0)
                {
                    ditu[x][y]=2;
                    x++;
                    ans++;
                }
                else if(ditu[x+1][y]==2)
                {
                    ditu[x][y]=2;
                    x++;
                }
                else
                {
                    d++;
                }
            }
            else if(d==2)
            {
                if(ditu[x][y-1]==0)
                {
                    ditu[x][y]=2;
                    y--;
                    ans++;
                }
                else if(ditu[x][y-1]==2)
                {
                    ditu[x][y]=2;
                    y--;
                }
                else
                {
                    d++;
                }
            }
            else
            {
                if(ditu[x-1][y]==0)
                {
                    ditu[x][y]=2;
                    x--;
                    ans++;
                }
                else if(ditu[x-1][y]==2)
                {
                    ditu[x][y]=2;
                    x--;
                }
                else
                {
                    d=0;
                }
            }
        }
        cout<<ans<<endl;
        ans=1;
    }
    return 0;
}
