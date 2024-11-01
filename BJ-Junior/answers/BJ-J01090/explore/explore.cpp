#include<bits/stdc++.h>
using namespace std;
bool mp[1010][1010];
bool cnt[1010][1010];
int T;
int m,n;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int x_0,y_0,k0,d0;
int ans;
void dfs(int x,int y,int d,int k)
{
    if(k==0) return ;
    int x1=x+dx[d];
    int y1=y+dy[d];
    if(x1>0 && x1<=n && y1>0 && y1<=m && mp[x1][y1])
    {
        cnt[x1][y1]=1;
        dfs(x1,y1,d,k-1);
    }else
    {
        dfs(x,y,(d+1)%4,k-1);
    }
}
char in;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(;T>0;T--)
    {
        memset(mp,0,sizeof(mp));
        memset(cnt,0,sizeof(cnt));
        ans=0;
        //cout<<"*";
        cin>>n>>m>>k0;
        cin>>x_0>>y_0>>d0;
        //cout<<"*";
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>in;
                if(in=='.') mp[i][j]=1;
                //cout<<i<<"*"<<j<<endl;
                //cout<<"*";
            }
            //cout<<"*";
        }
        //cout<<"*";
        cnt[x_0][y_0]=1;
        dfs(x_0,y_0,d0,k0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(cnt[i][j]==1) ans++;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
