#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k,x,y,d,ans;
char a[1001][1001];
int dfs(int n,int m,int k,int x,int y,int d)
{
    if(!k)return ans;
    if(a[x][y]=='.')
        ans++;
    if(d==0&&y+1<=m)
        return dfs(n,m,k-1,x,y+1,d);
    else if(d==0&&y+1>m)
        return dfs(n,m,k-1,x,y,(d+1)%4);
    else if(d==1&&x+1<=m)
        return dfs(n,m,k-1,x+1,y,d);
    else if(d==1&&x+1>n)
        return dfs(n,m,k-1,x,y,(d+1)%4);
    else if(d==2&&y-1>0)
        return dfs(n,m,k-1,x,y-1,d);
    else if(d==2&&y-1<=0)
        return dfs(n,m,k-1,x,y,(d+1)%4);
    else if(d==3&&x-1>0)
        return dfs(n,m,k-1,x-1,y,d);
    else if(d==3&&x-1<=0)
        return dfs(n,m,k-1,x,y,(d+1)%4);

}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++)
            for(int z=1;z<=m;z++)
                cin>>a[j][z];
        cout<<dfs(n,m,k,x,y,d)<<endl;
    }
    return 0;
}
