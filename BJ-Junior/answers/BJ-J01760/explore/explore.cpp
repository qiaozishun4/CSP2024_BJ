#include <bits/stdc++.h>
using namespace std;
char exl[1023][1023];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool vis[1023][1023];
int a,n,m,k,direct,rx,ry;
int cnt;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cnt=0;
        memset(exl,0,sizeof(exl));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>rx>>ry>>direct;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
                cin>>exl[j][k];
        }
        vis[rx][ry]=1;
        cnt++;
        for(int j=0;j<k;j++)
        {
            if(rx+dx[direct]>0&&rx+dx[direct]<=n&&ry+dy[direct]>0&&ry+dy[direct]<=m&&exl[rx+dx[direct]][ry+dy[direct]]=='.')
            {
                rx+=dx[direct];
                ry+=dy[direct];
                if(!vis[rx][ry])
                {
                    vis[rx][ry]=1;
                    cnt++;
                }
            }
            else
                direct=(direct+1)%4;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
