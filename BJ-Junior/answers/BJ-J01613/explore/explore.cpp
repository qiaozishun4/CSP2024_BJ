#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],ans,r[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};

int n,m,k,x,y,d,lx,ly;
void dfs(int g,int x2,int y2)
{
    a[x2][y2]=0;
    if(g==k+1)
    {
        return;
    }
    int x_=x2+r[d][0],y_=y2+r[d][1];
    if(a[x_][y_]==1 && lx!=x_ &&ly!=y_)
    {
        ans++;

        dfs(g+1,x_,y_);
    }
    else
    {
        d=(d+1)%4;
        dfs(g+1,x2,y2);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                char c;
                cin>>c;
                if(c=='.') a[i][j]=1;
            }
        }

        ans=1;
        dfs(1,x,y);
        cout<<ans<<endl;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                a[i][j]=0;
            }
        }

    }
    return 0;
}
