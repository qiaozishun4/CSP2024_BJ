#include<bits/stdc++.h>
using namespace std;
const int inf = 1e6;
int dp[101][10000];
int f[10000][10000];
int tmp[10000];
int shou_pai[100001];
int main ()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k,q,l;
        scanf("%d%d%d",&n,&k,&q);
        memset(dp,-1,sizeof(dp));
        memset(f,-1,sizeof(f));
        for (int p = 1;p <= n;p++)
        {
            scanf("%d",&l);
            for (int i = 1;i <= l;i++) scanf("%d",&shou_pai[i]);
            int pos = max(l - k + 1,1);
            for (int i = 0;i < 10;i++) tmp[i] = 0;
            tmp[shou_pai[l]]++;
            for (int i = l - 1;i > pos;i--)
            {
                for (int j = 0;j < 10;j++)
                {
                    if(tmp[j])
                    {
                        if(f[shou_pai[i]][j] == -1) f[shou_pai[i]][j] = p;
                        else if(f[shou_pai[i]][j] <= n) f[shou_pai[i]][j] = inf;
                    }
                }
                tmp[shou_pai[i]]++;
            }
            for (int i = pos;i >= 1;i--)
            {
                for (int j = 0;j < 10;j++)
                {
                    if(tmp[j])
                    {
                        if(f[shou_pai[i]][j] == -1) f[shou_pai[i]][j] = p;
                        else if(f[shou_pai[i]][j] <= n) f[shou_pai[i]][j] = inf;
                    }
                }
                tmp[shou_pai[i]]++;
                tmp[shou_pai[i + k - 1]]--;
            }
        }
        for (int i = 0;i < 10;i++) dp[1][i] = f[1][i];
        for (int lun = 2;lun <= 100;lun++)
        {
            for (int i = 0;i < 10;i++)
            {
                if(dp[lun - 1][i] == -1) continue;
                for (int j = 0;j < 10;j++)
                {
                    if(f[i][j] == -1) continue;
                    if(f[i][j] == inf) dp[lun][j] = inf;
                    else if(dp[lun - 1][i] == inf) dp[lun][j] = f[i][j];
                    else if(dp[lun - 1][i] != f[i][j]) dp[lun][j] = f[i][j];
                }
            }
        }
        int x,y;
        while(q--)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",dp[x][y] == -1?0:1);
        }
    }
    return 0;
}
