#include <bits/stdc++.h>

using namespace std;
int t,e;
int n,m,k;
int a,b,d,q;
string mape[1001];
int o[1001][1001];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int dfs(int c,int x,int y,int d)
{
    o[x][y]++;
    if(c==k)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(o[i][j])
                {
                    e++;
                }
            }
        }
        cout<<e<<endl;
        e=0;
        return 0;
    }
    if(x+dx[d]<n && x+dx[d]>=0&&y+dy[d]<m&&y+dy[d]>=0)
    {
        if(mape[x+dx[d]][y+dy[d]]=='.')
        {
            x=x+dx[d];
            y=y+dy[d];
            dfs(c+1,x,y,d);
        }
        else
        {
            d=(d+1)%4;
            dfs(c+1,x,y,d);
        }
    }
    else
    {
        d=(d+1)%4;
        dfs(c+1,x,y,d);
    }
    return 0;
}

int main()
{
    freopen("explore3.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m>>k;
        cin>>a>>b>>d;
        b-=1;
        a-=1;
        for(int j=0;j<n;j++)
        {
            cin>>mape[j];
        }
        e=0;
        dfs(0,a,b,d);
    }
    return 0;
}