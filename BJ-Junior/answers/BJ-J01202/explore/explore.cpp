#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
char a[1005][1005];
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
bool che[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int l=1;l<=t;++l)
    {
        memset(che,0,sizeof(che));
        int ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        che[x][y]=1;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                cin>>a[i][j];
            }
        for(int i=1;i<=k;++i)
        {
            if(x+xx[d]<1||x+xx[d]>n||y+yy[d]<1||y+yy[d]>m)
            {
                d=(d+1)%4;
            }
            else if(a[x+xx[d]][y+yy[d]]=='x')
            {
                d=(d+1)%4;
            }
            else
            {
                x+=xx[d];
                y+=yy[d];
                if(che[x][y]!=1)
                {
                    ans++;
                    che[x][y]=1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
