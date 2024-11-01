#include<bits/stdc++.h>
using namespace std;
int ans[15000];
int main()
{
	int n,i=1,t;
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--)
	{
		i=1;
		cin>>n;
		if(n<7)
		{
			if(n==2) ans[1]=1;
			else if(n==3) ans[1]=7;
			else if(n==4) ans[1]=4;
			else if(n==5) ans[1]=2;
			else if(n==6) ans[1]=6;
		}
		else
		{
			while(n>=7)
			{
				ans[i]=8;
				n/=7;
				i++;
			}
			if(n==1)
			{
				ans[i]=2;
				ans[i-1]=0;
				ans[i-2]=0;
				ans[i-3]=0;
				ans[i-4]=0;
			}
			else if(n==2)
			{
				ans[i]=2;
				ans[i-1]=0;
				ans[i-2]=0;
				ans[i-3]=0;
			}
			else if(n==3)
			{
				ans[i]=2;
				ans[i-1]=0;
				ans[i-2]=0;
			}
			else if(n==4)
			{
				ans[i]=2;
				ans[i-1]=0;
			}
			else if(n==5)
			{
				ans[i]=2;
			}
			else if(n==6)
			{
				ans[i]=6;
			}
			else
			{
				i--;
			}
		}
		if(ans[1]==0) cout<<-1;
		else
		{
			int j;
			for(j=1;j<=i;j++) printf("%d",ans[j]);
		}
		printf("\n");
	}
	return 0;
}
