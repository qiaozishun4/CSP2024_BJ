#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int x,y,d;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int w=0;w<t;w++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        int ans=1;
        char a[n][m];
        bool z[n][m];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                z[i][j]=0;
            }
        }
        for(int i=1;i<=k;i++)
        {
            if(0<x&&x<=n&&0<y&&y<=m)
            {
                if(d%4==0)
                {
                    if(a[x][y+1]=='.'&&y!=m)
                    {
                        if(z[x][y+1]==0)
                            ans++;
                        y++;
                        z[x][y]=1;
                    }
                    else
                        d=(d+1)%4;
                }
                else if(d%4==1)
                {
                    if(a[x+1][y]=='.'&&x!=n)
                    {
                        if(z[x+1][y]==0)
                            ans++;
                        x++;
                        z[x][y]=1;
                    }
                    else
                        d=(d+1)%4;
                }
                else if(d%4==2)
                {
                    if(a[x][y-1]=='.'&&y!=1)
                    {
                        if(z[x][y-1]==0)
                            ans++;
                        y--;
                        z[x][y]=1;
                    }
                    else
                        d=(d+1)%4;
                }
                else if(d%4==3)
                {
                    if(a[x-1][y]=='.'&&x!=1)
                    {
                        if(z[x-1][y]==0)
                            ans++;
                        x--;
                        z[x][y]=1;
                    }
                    else
                        d=(d+1)%4;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
