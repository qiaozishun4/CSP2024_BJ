#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,A[209005],num[209005];
signed main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%lld",&n);
    for(ll i = 1;i <=n;i++)scanf("%lld",&A[i]);
    for(ll i = 1;i <=n;i++)num[A[i]]++;
    ll downnt=0,deadd=0;
    for(ll i = 1;i <=200000;i++)
    {
        if(downnt<=num[i])
        {
            deadd+=downnt;
            downnt=num[i];
        }
        else
        {
            deadd+=num[i];
        }
    }
    printf("%lld",n-deadd);
    return 0;
}
