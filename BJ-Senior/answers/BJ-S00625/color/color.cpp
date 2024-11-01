#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            sum+=x;
        }
        printf("%lld",sum/2);
    }
    return 0;
}
