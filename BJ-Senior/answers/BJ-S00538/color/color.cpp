#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int n, a[100010];
int f[100010];

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    scanf("%d",&t);
    for(int times = 1; times <= t; times++)
    {
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
        }
        int mul = 1;
        int maxn = 0;
        for(int i = 1; i <= n; i++) mul *= 2;
        for(int i = 0; i < mul; i++)
        {
            // printf("the %dth try:\n",i);
            int t = i;
            for(int j = 1; j <= n; j++)
            {
                f[j] = t % 2;
                t /= 2;
            }
            // for(int j = 1; j <= n; j++)
            //     printf("f[%d]=%d\n",j,f[j]);
            int later = 0, ans = 0;
            for(int j = 1; j <= n; j++)
            {
                later = 0;
                for(int k = j+1; k <= n; k++)
                {
                    if(f[k] == f[j] && a[k] == a[j])
                    {
                        later += a[k];
                        // printf("yeah, j=%d, k=%d, add %d\n",j,k,a[j]);
                        break;
                    }
                }
                ans += later;
            }
            // printf("ans =  %d\n",ans);
            maxn = max(maxn, ans);
        }
        printf("%d\n",maxn);
    }

    return 0;
}