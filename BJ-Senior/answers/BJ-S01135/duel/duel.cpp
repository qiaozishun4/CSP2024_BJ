#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N];
int lens;
int sz[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	int val=0;
	a[0]=-1e9;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			sz[lens]=val;
			lens++;
			val=0;
		}
		val++;	
	}
	sz[lens]=val;
	int sum=0;
	for(int i=lens;i>=1;i--)
	{
		sum+=sz[i]-min(sz[i],sum);
	}
	printf("%d",sum);
	return 0;
}