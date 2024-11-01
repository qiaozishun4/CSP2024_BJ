#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t,n,k,q,l,r,c,a[2 * N],h[2 * N];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n,&k,&q);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &l);
            for (int j = 1; j <= l; j++)
            {
                scanf("%d", &a[j]);
                h[a[j]]++;
            }
        }
        while (q--)
        {
            scanf("%d%d", &r,&c);
            if (!h[c] || c == 1 || (r == 1 && c > k))
            {
                printf("0\n");
                continue;
            }
            printf("1\n");
        }
    }
    return 0;
}
