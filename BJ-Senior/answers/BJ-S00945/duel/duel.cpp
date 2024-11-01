#include<iostream>
using namespace std;
#define maxn (int)1e5
#define maxr (int)1e5
long long n,r,ans=0;
long long cnt[maxn+10];
int main()
{
    //freopen("duel.in","r",stdin);
    //freopen("duel.out","w",stdout);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&r);
        cnt[r]++;
    }
    for(int i=0;i<=maxr;i++)
    {
        ans=max(ans-cnt[i],0ll);
        ans+=cnt[i];
    }
    printf("%lld\n",ans);
    return 0;
}
//CSP RP++
