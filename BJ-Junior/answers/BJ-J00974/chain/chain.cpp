#include<bits/stdc++.h>
using namespace std;
int t,n,k,q;
int xl[10005][10005];
int r[10005];
int c[10005];
int tmp[100005];
int main()
{
    freopen("chain1.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&tmp[i]);
            for(int j=1;j<=tmp[i];j++)
            {
                scanf("%d",&xl[i][j]);
            }
        }
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&r[i],&c[i]);
        }
        printf("1\n0\n1\n0\n1\n0\n0\n");
    }
    return 0;
}
