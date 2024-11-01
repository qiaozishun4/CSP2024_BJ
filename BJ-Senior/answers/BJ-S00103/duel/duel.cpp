#include<stdio.h>
#include<algorithm>
using namespace std;
const int NR=1e5+5;
int a[NR];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	sort(a+1,a+n+1);
	int l,r;
	for(l=1,r=1;r<=n;++r)
	{
		if(a[l]<a[r]) ++l;
	}
	printf("%d\n",n-l+1);
	return 0;
}