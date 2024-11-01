#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int t,n,m,k,x,y,d;
char mp[1005][1005];
int mark[1005][1005];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        string s;
        for(int i = 1;i<=n;i++)
        {
            cin>>s;
            for(int j = 1;j<=m;j++)
            {
                mp[i][j] = s[j-1];
                mark[i][j] = 0;
            }
        }
        mark[x][y] = 1;
        for(int i = 1;i<=k;i++)
        {
            int nx = x+dx[d],ny = y+dy[d];
            if(nx>n || nx<1 || ny>m || ny<1 || mp[nx][ny] == 'x')
            {
                d = (d+1)%4;
            }
            else
            {
                x = nx;
                y = ny;
                mark[x][y] = 1;
            }
        }
        int sum = 0;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(mark[i][j])
                    sum++;
            }
        }
        cout<<sum;
    }
    return 0;
}
