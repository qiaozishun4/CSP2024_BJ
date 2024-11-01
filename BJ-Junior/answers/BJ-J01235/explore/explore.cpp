#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    vector<int> ans;
    int tmp=t;
    while(t--)
    {
        int n,m,k,x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        char a[1005][1005];
        bool vis[1005][1005]={};
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        vis[x][y]=true;
        for(int i=0;i<k;i++)
        {
            if(d==0)
            {
                int ty=y+1;
                if(ty<=m&&ty>=1&&a[x][ty]=='.')
                {
                    vis[x][ty]=true;
                    y++;
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==1)
            {
                int tx=x+1;
                if(tx<=n&&tx>=1&&a[tx][y]=='.')
                {
                    vis[tx][y]=true;
                    x++;
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==2)
            {

                int ty=y-1;
                if(ty<=m&&ty>=1&&a[x][ty]=='.')
                {
                    vis[x][ty]=true;
                    y--;
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==3)
            {
                int tx=x-1;
                if(tx<=n&&tx>=1&&a[tx][y]=='.')
                {
                    vis[tx][y]=true;
                    x--;
                }
                else
                {
                    d=(d+1)%4;
                    continue;
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j]) cnt++;
            }
        }
        ans.push_back(cnt);
    }
    for(int i=0;i<tmp;i++)
    {
        cout<<ans[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
