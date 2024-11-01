#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char s[N][N];
bool flag[N][N];
int main ()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    int n,m,k,nowx,nowy,d,wx,wy;
    while(T--)
    {
        scanf("%d%d%d%d%d%d",&n,&m,&k,&nowx,&nowy,&d);
        for (int i = 1;i <= n;i++)
        {
            scanf("%s",s[i] + 1);
        }
        memset(flag,false,sizeof(flag));
        flag[nowx][nowy] = true;
        while(k--)
        {
            wx = nowx,wy = nowy;
            if(d == 0)
            {
                wy++;
            }
            else if(d == 1)
            {
                wx++;
            }
            else if(d == 2)
            {
                wy--;
            }
            else
            {
                wx--;
            }
            if(wx <= 0 || wx > n || wy <= 0 || wy > m || s[wx][wy] == 'x')
            {
                d = (d + 1) % 4;
            }
            else
            {
                nowx = wx,nowy = wy;
                flag[nowx][nowy] = true;
            }
        }
        int ans = 0;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                if(flag[i][j])
                {

                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
