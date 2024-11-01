#include <iostream>
using namespace std;
int t,n,m,k,x,y,d,ans;
int go[4][3]={{0, 0, 1},
              {0, 1, 0},
              {0, 0,-1},
              {0,-1, 0}};
bool ditu[1005][1005],did[1005][1005];
void doit()
{
    ans=0;
    for(int i=1;i<=n;i++)
    {
        string a;
        cin>>a;
        for(int j=1;j<=m;j++)
        {
            if(a[j-1]=='.')
                ditu[i][j]=true;
            else
                ditu[i][j]=false;
        }
    }
    did[x][y]=true;
    ans++;
    for(int i=1;i<=k;i++)
    {
        int tx,ty;
        tx=x+go[d][1];
        ty=y+go[d][2];
        if(tx>=1&&tx<=n)
        {
            if(ty>=1&&ty<=m)
            {
                if(ditu[tx][ty]==true)
                {
                    if(did[tx][ty]==false)
                    {
                        ans++;
                        did[tx][ty]=true;
                    }
                    x=tx;
                    y=ty;
                }
                else
                    d=(d+1)%4;
            }
            else
                d=(d+1)%4;
        }
        else
            d=(d+1)%4;
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            did[i][j]=false;
            ditu[i][j]=false;
        }
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int it=1;it<=t;it++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        doit();
    }
    return 0;
}
