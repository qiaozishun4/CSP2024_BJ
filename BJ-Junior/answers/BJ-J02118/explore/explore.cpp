#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
int x,y,d;
char map1[1005][1005];
int v[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>map1[i][j];
                v[i][j]=0;
            }
        }
        sum=1;
        v[x][y]=1;
        for(int i=1;i<=k;i++)
        {
            int nx=x,ny=y;
            if(d==0) ny++;
            else if(d==1) nx++;
            else if(d==2) ny--;
            else if(d==3) nx--;
            if(map1[nx][ny]!='.')
            {
                d=(d+1)%4;
                continue;
            }
            x=nx; y=ny;
            if(!v[x][y]) sum++;
            v[x][y]=1;
        }
        cout<<sum<<endl;
    }
}
