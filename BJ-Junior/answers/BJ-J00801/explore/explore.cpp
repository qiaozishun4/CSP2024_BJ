#include <bits/stdc++.h>
using namespace std;
struct nod
{
    char s;
    bool b;
} l[1005][1005];
int z[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
bool cango(int x,int y,int d,int n,int m)
{
    return x+z[d][0] >= 1 && x+z[d][0] <= n && y+z[d][1] >= 1 && y+z[d][1] <= m && l[x+z[d][0]][y+z[d][1]].s == '.';
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for (int i = 0;i < t;i++)
    {

        int n,m,k,x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for (int j = 1;j <= n;j++)
        {
            for (int k = 1;k <= m;k++)
            {
                cin>>l[j][k].s;
                l[j][k].b=0;
            }
        }
        int ans = 0;
        for (int j = 1;j <= k;j++)
        {
            if (!l[x][y].b)
            {
                l[x][y].b = true;
                ans++;
            }
            if (cango(x,y,d,n,m))
            {
                x+=z[d][0];
                y+=z[d][1];
            }
            else
            {
                d = (d+1) % 4;
            }
        }
        if (!l[x][y].b)
            {
                l[x][y].b = true;
                ans++;
            }
        cout<<ans<<"\n";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
