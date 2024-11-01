#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int T;
    cin>>T;
    for(int x=0;x<T;x++)
    {
        char exmap[1002][1002]={};
        bool vis[1002][1002]={};
        int n,m,k;
        cin>>n>>m>>k;
        int x0,y0,d;
        cin>>x0>>y0>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cin>>exmap[i][j];
        }
        int cnt=1;
        vis[x0][y0]=1;
        for(int i=0;i<k;i++)
        {
            if(x0+dx[d]>0&&x0+dx[d]<=n&&y0+dy[d]>0&&y0+dy[d]<=m&&exmap[x0+dx[d]][y0+dy[d]]=='.')
            {
                x0=x0+dx[d];
                y0=y0+dy[d];
                if(!vis[x0][y0])
                {
                    cnt++;
                    vis[x0][y0]=1;
                }
            }
            else
                d=(d+1)%4;
        }
        cout<<cnt<<endl;
    }
    fclose("explore.in");
    fclose("explore.out");
    return 0;
}
