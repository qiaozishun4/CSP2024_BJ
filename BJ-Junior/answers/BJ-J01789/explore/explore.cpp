#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int T,n,m;
int xx,yy,d,k;
int ans;
string s1;
char f[maxn][maxn];
bool vis[maxn][maxn];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>n>>m>>k;
        cin>>xx>>yy>>d;
        vis[xx][yy]=1;
        for(int i=1;i<=n;++i)
        {
            cin>>s1;
            for(int j=1;j<=m;++j)
                f[i][j]=s1[j-1];

        }

        while(k--)
        {
            if(d==0)
            {
                if(f[xx][yy+1]=='x'||yy+1>m)
                {
                    d+=1;
                    d%=4;
                    continue;
                }
                else
                {
                    ++yy;
                    vis[xx][yy]=1;
                }
            }
            if(d==1)
            {
                if(f[xx+1][yy]=='x'||xx+1>n)
                {
                    d+=1;
                    d%=4;
                    continue;
                }
                else
                {
                    ++xx;
                    vis[xx][yy]=1;
                }
            }
            if(d==2)
            {
                if(f[xx][yy-1]=='x'||yy-1<=0)
                {
                    d+=1;
                    d%=4;
                    continue;
                }
                else
                {
                    --yy;
                    vis[xx][yy]=1;
                }
            }
            if(d==3)
            {
                if(f[xx-1][yy]=='x'||xx-1<=0)
                {
                    d+=1;
                    d%=4;
                    continue;
                }
                else
                {
                    --xx;
                    vis[xx][yy]=1;
                }
            }
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                if(vis[i][j])
                {
                    ++ans;
                    vis[i][j]=0;
                }
        cout<<ans<<"\n";
    }
    return 0;
}
