#include<bits/stdc++.h>
using namespace std;
int x,n;
int sti[15]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int minn=1e9;
		x=ceil(n/7.0);
		int i=pow(10,x)-1;
		for(int k=1;k<=i;k++)
		{
			int j=k,ans=0;
			while(j>0)
			{
				if(ans>n) break;
				ans+=sti[j%10];
				j/=10;
			}
			if(ans==n) 
			{
				minn=k;
				break;
			}
		}
		if(minn==1e9) printf("-1\n");
		else printf("%d\n",minn);
	}
	return 0;
}
