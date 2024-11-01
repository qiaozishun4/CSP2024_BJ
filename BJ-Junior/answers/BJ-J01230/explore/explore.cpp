#include <iostream>
using namespace std;
const int N=1e3+5;
char mp[N][N];
bool vis[N][N];
int T;
int cnt=1;
int nn,mm,kk;
int pos1[4]={0,1,0,-1};
int pos2[4]={1,0,-1,0};
void dfs(int x,int y,int d,int step)
{
    if(step==0)return;
    vis[x][y]=1;
    int newx=x+pos1[d];
    int newy=y+pos2[d];
    if(newx>=1&&newx<=nn&&newy>=1&&newy<=mm&&mp[newx][newy]=='.')
    {
        if(vis[newx][newy]==0)
        {
            cnt++;
            dfs(newx,newy,d,step-1);
        }
        else
        {
            dfs(newx,newy,d,step-1);
        }
    }
    else
    {
        dfs(x,y,(d+1)%4,step-1);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>nn>>mm>>kk;
        int x0,y0,d0;
        cin>>x0>>y0>>d0;
        cnt=1;
        for(int i=1;i<=nn;i++)
        {
            for(int j=1;j<=mm;j++)
            {
                vis[i][j]=0;
            }
        }
        for(int i=1;i<=nn;i++)
        {
            for(int j=1;j<=mm;j++)
            {
                cin>>mp[i][j];
            }
        }
        dfs(x0,y0,d0,kk);
        cout<<cnt<<endl;
    }
    return 0;
}