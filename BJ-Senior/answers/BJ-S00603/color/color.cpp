#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000005;
int cnt[N];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T,n,x;
    scanf("%d",&T);
    long long res=0;
    while (T--)
    {
        res=0;
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            cnt[x]++;
            if (cnt[x]==2) res+=x;
            if (cnt[x]==3) res-=x;
        }
        printf("%lld\n",res);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
