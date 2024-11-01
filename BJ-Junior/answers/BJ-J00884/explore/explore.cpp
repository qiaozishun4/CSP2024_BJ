#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int vis[1010][1010],n,m;
long long cnt=1;
void dfs(int x,int y,int d,int sum)
{
    if(sum==0) return;
    int x1=x,y1=y;
    if(d==0)
    {
        y1=y+1;
    }
    else if(d==1)
    {
        x1=x+1;
    }
    else if(d==2)
    {
        y1=y-1;
    }
    else if(d==3)
    {
        x1=x-1;
    }
    if(x1>n||y1>m||x1<1||y1<1||a[x1][y1]=='x')
    {
        d=(d+1)%4;
        dfs(x,y,d,sum-1);
    }
    else
    {
        if(vis[x1][y1]==0)
        {
            vis[x1][y1]=1;
            cnt++;
        }
        dfs(x1,y1,d,sum-1);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int l=1;l<=T;l++)
    {
        cnt=1;
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        int k,s1,s2,d;
        cin>>n>>m>>k;
        cin>>s1>>s2>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        vis[s1][s2]=1;
        dfs(s1,s2,d,k);
        cout<<cnt<<endl;
    }
    return 0;
}

