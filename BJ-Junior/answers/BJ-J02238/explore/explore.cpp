#include<iostream>
#include<cstring>
using namespace std;
int t,n,m,k,x,y,d,ans;
char s[1005][1005];
bool a[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        ans=1;
        memset(a,0,sizeof(a));
        a[x][y]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>s[i][j];
        for(int i=1;i<=k;i++)
        {
            if(d==0&&1<=x&&x<=n&&1<=y+1&&y+1<=m&&s[x][y+1]=='.')
            {
                y++;
                if(a[x][y]==0)
                {

                    a[x][y]=1;
                    ans++;
                }
            }
            else if(d==1&&1<=x+1&&x+1<=n&&1<=y&&y<=m&&s[x+1][y]=='.')
            {
                x++;
                if(a[x][y]==0)
                {

                    a[x][y]=1;
                    ans++;
                }
            }
            else if(d==2&&1<=x&&x<=n&&1<=y-1&&y-1<=m&&s[x][y-1]=='.')
            {
                y--;
                if(a[x][y]==0)
                {

                    a[x][y]=1;
                    ans++;
                }
            }
            else if(d==3&&1<=x-1&&x-1<=n&&1<=y&&y<=m&&s[x-1][y]=='.')
            {
                x--;
                if(a[x][y]==0)
                {

                    a[x][y]=1;
                    ans++;
                }
            }
            else d=(d+1)%4;
        }
        cout<<ans<<endl;
    }
    return 0;
}


