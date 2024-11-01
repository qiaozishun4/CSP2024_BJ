#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int ans,d,fx[4]={0,1,0,-1},fy[4]={1,0,-1,0},k,m,n,t,x,y;
bool f[105][105];
//判断当前点能否访问
bool check(int x,int y)
{
    if (x<=n&&y<=m&&x>=1&&y>=1&&a[x][y]!='x')
    {
        return true;
    }
    return false;
}
//深搜标记访问的点
void dfs(int x,int y,int d,int k)
{
    f[x][y]=true;
    if (k==0)
    {
        return;
    }
    bool tmp=false;
    for (int i=0;i<=3;i++)
    {
        if (check(x+fx[i],y+fy[i]))
        {
            tmp=true;
            break;
        }
    }
    if (!tmp)
    {
        return;
    }
    //更新下一个要去的点的坐标
    int tx=x+fx[d];
    int ty=y+fy[d];
    //如果下一个点可以访问，深搜到下一节点
    if (check(tx,ty))
    {
        dfs(tx,ty,d,k-1);
    }
    //否则改变方向
    else 
    {
        dfs(x,y,(d+1)%4,k-1);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n>>m>>k>>x>>y>>d;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        //深搜
        dfs(x,y,d,k);
        //遍历整个地图判断每个点是否被访问
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (f[i][j]==true)
                {
                    ans++;
                    f[i][j]=false;
                }
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}