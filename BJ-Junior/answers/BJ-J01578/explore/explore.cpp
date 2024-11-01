#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
char a[1005][1005];
bool f[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                cin>>a[j][k];
                f[j][k]=false;
            }
        }
        ans=0;
        if(!f[x][y])
        {
            f[x][y]=true;
            ans++;
        }
        for(int j=1;j<=k;j++)
        {
            if(d==0)
            {
                if(y+1<=m&&a[x][y+1]!='x')
                {
                    y++;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==1)
            {
                if(x+1<=n&&a[x+1][y]!='x')
                {
                    x++;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==2)
            {
                if(y-1>=1&&a[x][y-1]!='x')
                {
                    y--;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            else if(d==3)
            {
                if(x-1>=1&&a[x-1][y]!='x')
                {
                    x--;
                }
                else
                {
                    d=(d+1)%4;
                }
            }
            if(!f[x][y])
            {
                f[x][y]=true;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
