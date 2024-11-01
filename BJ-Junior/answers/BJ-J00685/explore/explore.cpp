#include<bits/stdc++.h>
using namespace std;
int t,n=1000,m=1000,k,x,y,d,ch[1010][1010],ans;
char a[1010][1010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ans=0;
        for(int j=1;j<=n+1;j++)
        {
            for(int p=1;p<=m+1;p++)
            {
                a[j][p]=' ';
                ch[j][p]=0;
            }
        }
        cin>>n>>m>>k>>x>>y>>d;
        ch[x][y]++;
        for(int j=1;j<=n;j++)
        {
            for(int p=1;p<=m;p++)
            {
                cin>>a[j][p];
            }
        }
        for(int j=1;j<=k;j++)
        {
            if(d==0&&a[x][y+1]=='.')
            {
                y++;
                ch[x][y]++;
            }
            else if(d==1&&a[x+1][y]=='.')
            {
                x++;
                ch[x][y]++;
            }
            else if(d==2&&a[x][y-1]=='.')
            {
                y--;
                ch[x][y]++;
            }
            else if(d==3&&a[x-1][y]=='.')
            {
                x--;
                ch[x][y]++;
            }
            else d=(d+1)%4;
        }
        for(int j=1;j<=n;j++)
        {
            for(int p=1;p<=m;p++)
            {
                if(ch[j][p]!=0) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
