#include <bits/stdc++.h>
using namespace std;
long long n,num,ans,a[100100],l=100100,r=0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%lld",&n);
    for(int i = 1;i <= n;++i)
    {
		scanf("%lld",&num);
		++a[num];
		r=max(r,num);
		l=min(l,num);
	}
	ans=a[l];
    for(int i = l+1;i <= r;++i)
    {
		if(a[i]>ans) ans=a[i];
		else ans=ans;
	}
    printf("%lld",ans);
    return 0;
}
