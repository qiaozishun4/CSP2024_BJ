#include <bits/stdc++.h>
using namespace std;
int a[1500][1500];
int t;
int n,m,k;
int x,y,d;
int cnt;
int v[1500][1500];
const int px[4]={0,1,0,-1};
const int py[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        cnt=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char pp;
                cin>>pp;
                if(pp=='.')
                    a[i][j]=1;
            }
        }
        k++;
        while(k--)
        {
            if(v[x][y]==0)
            {
                cnt++;
            }
            int nx=x+px[d];
            int ny=y+py[d];
            v[x][y]=1;
            if(nx>n || nx<1 || ny>m || ny<1)
            {
                d=(d+1)%4;
                continue;
            }
            if(a[nx][ny]==0)
            {
                d=(d+1)%4;
                continue;
            }
            x=nx;
            y=ny;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
