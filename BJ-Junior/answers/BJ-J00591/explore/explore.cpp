#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n,m,i0,j0,d,xx[5] = {0,1,0,-1},yy[5] = {1,0,-1,0},t,bok[1001][1001] = {},xn,yn,xxx,yyy,k,ans;
    char mp[1001][1001]= {};
    cin >> t;
    for(int q = 1;q<=t;q++)
    {
       cin >> n >> m >> k>>xn>>yn>>d;
       bok[xn][yn] = q;
       ans = 1;
       for(int i = 1;i<= n;i++)
       {
           for(int j = 1;j<=m;j++)
           {
               cin >> mp[i][j];
           }
       }
       for(int i = 1;i<=k;i++)
       {
           yyy = yn+yy[d];
           xxx = xn+xx[d];
           if(mp[xxx][yyy] == '.'&&xxx>0&&yyy>0&&xxx<=n&&yyy<=m)
           {
               xn=xxx;
               yn=yyy;
               if(bok[xn][yn]<q)
               {
                   ans++;
                   bok[xn][yn] = q;
               }
           }
           else
           {
               d = (d + 1) % 4;
           }
       }
       cout << ans << endl;
    }
    return 0;
}
