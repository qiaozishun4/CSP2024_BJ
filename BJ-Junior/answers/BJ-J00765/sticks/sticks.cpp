#include<bits/stdc++.h>
using namespace std;
int t;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int a[1000001];
int b[1000001];
int c;
inline void f(int n,int sum)
{
	if(n==0)
	{
		int ans=0;
		for(int i=1;i<sum;i++)
		{
			ans=ans*10+a[i];
//			printf("%d %d\n",a[i],num[a[i]]);
		}
		b[c]=min(b[c],ans);
//		printf("\n");
		return;
	}
	if(n<0)
	{
		return;
	}
	for(int i=0;i<=9;i++)
	{
		if(n<num[i])continue;
		if(sum==1&&i==0)continue;
		a[sum]=i;
		f(n-num[i],sum+1);
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	memset(b,0x3f3f3f3f,sizeof(b));
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int n;
		scanf("%d",&n);
		c=n;
		if(b[n]!=0x3f3f3f3f)
		{
			printf("%d\n",b[n]);
			continue;
		}
		if(n%7==0)
		{
			for(int j=1;j<=n/7;j++)
			{
				printf("8");
			}
			continue;
		}
		f(n,1);
		if(b[n]==0x3f3f3f3f){
			printf("-1\n");
			continue;
		}
		printf("%d\n",b[n]);
	}
	return 0;
}
