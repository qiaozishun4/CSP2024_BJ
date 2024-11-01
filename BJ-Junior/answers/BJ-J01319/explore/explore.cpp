#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
bool flag[1001][1001];
int tox[4] = {0,1,0,-1},toy[4] = {1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin>>a[i][j];
                flag[i][j] = 0;
            }
        }
        int ans = 1;
        flag[x][y] = 1;
        for(int i = 1;i <= k;i++)
        {
            if(a[x + tox[d]][y + toy[d]] == '.')
            {
                if(!flag[x + tox[d]][y + toy[d]])
                    ans++;
                x += tox[d];
                y += toy[d];
                flag[x][y] = true;
            }
            else
                d = (d + 1) % 4;
        }
        cout<<ans<<endl;
    }
}
