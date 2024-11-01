#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
const int NR=2e5+5;
const int MR=1e6+5;
int a[NR];
LL s[NR];
LL maxc[MR];
LL f[NR];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",a+i);
		a[0]=1e6+1,a[n+1]=1e6+2;
		memset(maxc,0xc0,sizeof(maxc));
		LL maxx=0;
		for(int i=1;i<=n;++i)
		{
			s[i]=s[i-1]+(a[i]==a[i-1])*a[i];
		}
		for(int i=1;i<=n;++i)
		{
			f[i]=max(maxx+s[i],maxc[a[i+1]]+s[i]+a[i+1]);
			maxc[a[i]]=max(maxc[a[i]],f[i]-s[i+1]);
			maxx=max(maxx,f[i]-s[i+1]);
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}