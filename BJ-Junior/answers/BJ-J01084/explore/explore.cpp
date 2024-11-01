#include<bits.stdc++.h>
using namespace std;
char a[1010][1010];
bool vis[1010][1010];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main()
{
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        for(int j = 0;j < 1010;j++)
        {
            for(int l = 0;l < 1010;l++)
            {
                vis[j][l] = false;
            }
        }
        int n,m,k;
        int x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j = 1;j <= n;j++)
        {
            for(int l = 1;l <= m;l++)
            {
                cin>>a[j][l];
            }
        }
        for(int j = 1;j <= k;j++)
        {
            vis[x][y] = true;
            if(a[x+dx[d]][y+dy[d]] == '.')
            {
                x = x + dx[d];
                y = y + dy[d];
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        int ans = 0;
        for(int j = 1;j <= n;j++)
        {
            for(int l = 1;l <= m;l++)
            {
                if(vis[j][l] == true)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}