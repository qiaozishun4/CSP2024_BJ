#include<iostream>
#include<string>
using namespace std;
int t;
bool a[1010][1010];
int d_ch(int d)
{
    if(d<=2)return d+1;
    return 0;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int w=1;w<=t;w++)
    {
        int n,m,k;
        int x,y,d;
        bool vis[1010][1010];
        long long ans=0;
        string s;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            for(int j=1;j<=m;j++)
            {
                if(s[j-1]=='.')a[i][j]=1;
                else a[i][j]=0;
                vis[i][j]=0;
            }
        }
        for(int i=1;i<=k;i++)
        {
            vis[x][y]=1;
            bool tmp=0;
            if(d==0 && y<m && a[x][y+1])
            {
                y++;
                tmp=1;
            }
            if(d==1 && x<n && a[x+1][y])
            {
                x++;
                tmp=1;
            }
            if(d==2 && y>1 && a[x][y-1])
            {
                y--;
                tmp=1;
            }
            if(d==3 && x>1 && a[x-1][y])
            {
                x--;
                tmp=1;
            }
            if(!tmp)d=d_ch(d);
        }
        vis[x][y]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(vis[i][j])ans++;
        cout<<ans<<endl;
    }
    return 0;
}
