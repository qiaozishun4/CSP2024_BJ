#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,tempx,tempy,tempd,ans=1;
int a[1010][1010];
bool b[1010][1010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        ans=1;
        x=0,y=0,k=0;
        char ch;
        cin>>n>>m>>k;
        cin>>tempx>>tempy>>tempd;
        x=tempx;
        y=tempy;
        d=tempd;
        b[x][y]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>ch;
                if(ch=='.') a[i][j]=0;
                else if(ch=='x') a[i][j]=1;
            }
        }
        for(int step=1;step<=k;step++)
        {
            if(d==0)
            {
                if(x>=1&&y+1>=1&&x<=n&&y+1<=m&&a[x][y+1]==0)
                {
                    x=x;
                    y=y+1;
                    if(b[x][y]==0)
                    {
                        b[x][y]=1;
                        ans++;
                    }
                    else if(b[x][y]==1)
                    {
                        b[x][y]=1;
                    }
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }
            }
            else if(d==1)
            {
                if(x+1>=1&&y>=1&&x+1<=n&&y<=m&&a[x+1][y]==0)
                {
                    x=x+1;
                    y=y;
                    if(b[x][y]==0)
                    {
                        b[x][y]=1;
                        ans++;
                    }
                    else if(b[x][y]==1)
                    {
                        b[x][y]=1;
                    }
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }
            }
            else if(d==2)
            {
                if(x>=1&&y-1>=1&&x<=n&&y-1<=m&&a[x][y-1]==0)
                {
                    x=x;
                    y=y-1;
                    if(b[x][y]==0)
                    {
                        b[x][y]=1;
                        ans++;
                    }
                    else if(b[x][y]==1)
                    {
                        b[x][y]=1;
                    }
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }
            }
            else if(d==3)
            {
                if(x-1>=1&&y>=1&&x-1<=n&&y<=m&&a[x-1][y]==0)
                {
                    x=x-1;
                    y=y;
                    if(b[x][y]==0)
                    {
                        b[x][y]=1;
                        ans++;
                    }
                    else if(b[x][y]==1)
                    {
                        b[x][y]=1;
                    }
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }
            }
        }
        cout<<ans<<endl;
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
