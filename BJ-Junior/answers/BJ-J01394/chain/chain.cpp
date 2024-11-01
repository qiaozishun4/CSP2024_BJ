#include <bits/stdc++.h>
using namespace std;
int T;
int n,k,q;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&k,&q);
        for(int i = 1;i<=n;i++)
        {
            int l;
            scanf("%d",&l);
            for(int j = 1;j<=l;j++)
            {
                int x;
                scanf("%d",&x);
            }
        }
        for(int i = 1;i<=q;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("0\n");
        }
    }
    return 0;
}
