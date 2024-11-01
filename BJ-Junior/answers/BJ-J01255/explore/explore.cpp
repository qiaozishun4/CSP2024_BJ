#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k,x,y,d;
string input;
int jungle[1001][1001],vis[1001][1001],ans;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=0;i<n;i++)
        {
            cin>>input;
            for(int j=0;j<m;j++)
            {
                jungle[i+1][j+1]=(input[j]=='x');
                vis[i+1][j+1]=0;
            }
        }
        ans=1;vis[x][y]=d+4;
        while(k--)
        {
            int x1=x+dx[d],y1=y+dy[d];
            if(x1>0&&x1<=n&&y1>0&&y1<=m&&jungle[x1][y1]==0)
            {
                x=x1;y=y1;
            }
            else
            {
                d=(d+1)%4;
            }
            if(vis[x][y]==d+4) break;
            else if(vis[x][y]==0)
            {
                vis[x][y]=d+4;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
