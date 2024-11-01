#include<bits/stdc++.h>
using namespace std;
#define fio(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)

const int dx[]={0,1,0,-1},
          dy[]={1,0,-1,0};

int T,n,m,k,x,y,d,ans;
bool mp[1005][1005],vis[1005][1005];

int main()
{
    fio("explore");
    /*cin>>T>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            char minpt;
            cin>>minpt;
            if(minpt=='x') mp[i][j]=true;
            else mp[i][j]=false;
        }
    for(int i=y-10;i<=y+50;i++) cout<<mp[1][i];*/
    cin>>T;
    while(T--)
    {
        memset(vis,0,sizeof(vis)),ans=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            char minpt;
            cin>>minpt;
            if(minpt=='x') mp[i][j]=true;
            else mp[i][j]=false;
        }
        //cout<<"         "<<n<<" "<<m<<"\n";
        for(;k>=1;k--)
        {
            //cout<<"           "<<x<<" "<<y<<" "<<d<<" "<<k<<"\n";
            int newx=x+dx[d],newy=y+dy[d];
            if(mp[newx][newy]||newx>n||newx<1||newy>m||newy<1) d=(d+1)%4;
            else if(!vis[newx][newy]) vis[x][y]=true,x=newx,y=newy,ans++;
            else vis[x][y]=true,x=newx,y=newy;
        }
        cout<<ans<<"\n";
    }
}
