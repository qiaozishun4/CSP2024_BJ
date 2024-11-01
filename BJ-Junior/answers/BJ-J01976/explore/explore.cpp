#include<bits/stdc++.h>
using namespace std;
long long n,m,T,zx[10]={1,0,-1,0},zy[10]={0,1,0,-1},flag[1010][1010],ans;
char lj[1010][1010];
string str;
int dfs(int x,int y,int d,int k)
{
    if(flag[y][x]==0)
    {
        ans++;
    }
    if(k==0)
    {
        return 0;
    }
    flag[y][x]++;
    if(x+zx[d]<=m&&x+zx[d]>0&&y+zy[d]<=n&&y+zy[d]>0&&lj[y+zy[d]][x+zx[d]]=='.')
    {
        dfs(x+zx[d],y+zy[d],d,k-1);
    }
    else
    {
        dfs(x,y,(d+1)%4,k-1);
    }
    flag[y][x]--;
    return 0;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(T=T;T>0;T--)
    {
        ans=0;
        int x,y,d,k;
        cin>>n>>m>>k;
        cin>>y>>x>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>str;
            for(int j=1;j<=m;j++)
            {
                lj[i][j]=str[j-1];
            }
        }
        dfs(x,y,d,k);
        cout<<ans<<endl;
    }
    return 0;
}
