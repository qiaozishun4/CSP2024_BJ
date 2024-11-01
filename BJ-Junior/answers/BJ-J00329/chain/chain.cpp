#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=2e5+5;
int T;
int n,k,q;//k:2e5
int len[N];//qian zhui he
int s[M];

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&n,&k,&q);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&len[i]);
            len[i]+=len[i-1];
            for (int j=len[i-1]+1;j<=len[i];j++) scanf("%d",&s[j]);
        }
        for (int i=1;i<=q;i++)
        {
            int r,c;
            scanf("%d%d",&r,&c);
            int ans=0;
            printf("%d\n",ans);
        }
    }
    return 0;
}
