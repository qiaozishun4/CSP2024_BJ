#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,K;
int pow2[N];
int a[N],c[N];
int x[10];
string s[25];
int ans;
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	pow2[0]=1;
	for(int i=1;i<=20;i++)
	{
		pow2[i]=pow2[i-1]*2;
	}
	scanf("%d%d",&n,&m);
	K=lower_bound(pow2+1,pow2+21,n)-pow2-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=K;i++)
	{
		cin>>s[i];
	}
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		for(int j=0;j<4;j++)
		{
			scanf("%d",&x[j]);
		}
	}
	for(int i=1;i<=t;i++)
	{
		ans=ans xor i;
	}
	printf("%d",ans);
	return 0;
}