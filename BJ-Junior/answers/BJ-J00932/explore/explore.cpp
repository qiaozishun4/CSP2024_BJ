#include<bits/stdc++.h>
using namespace std;
char dis[1001][1001];
int vis[1001][1001];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k,sx,sy,d,ans=1,l=0;
        cin>>n>>m>>k;
        cin>>sx>>sy>>d;
        //cout<<6<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>dis[i][j];
                vis[i][j]=0;
                //cout<<l<<endl;
                l++;
            }
        }
        vis[sx][sy]++;
        while(k)
        {
            if(dis[sx+dx[d]][sy+dy[d]]!='x' && sx+dx[d]<=n && sx+dx[d]>=1 && sy+dy[d]<=m && sy+dy[d]>=1)
            {
                sx+=dx[d];
                sy+=dy[d];
                k--;
                ans+=1-vis[sx][sy];
                vis[sx][sy]=1;
                //cout<<sx<<" "<<sy<<endl;
            }
            else
            {
                k--;
                d++;
                d%=4;
                //cout<<sx<<" "<<sy<<" "<<d<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
