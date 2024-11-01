#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6},dp[10]={1,7,4,2,3,5,0,6,9,8},ans[100005];
void stick(int n)
{
	int t=min(n/a[dp[9]],n/a[0]);
	sort(a+1,a+n+1);
	for(int j=t+1;j>=1;j++)
	{
		for(int i=0;i<10;i++)
		{
			if(i==dp[1]||a[i]==a[9])
			{
				ans[j]=i;
			}
		}
	}
	for(int i=1;i<=t+1;i++)
	{
		cout<<ans[i];
	}
	
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout)
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		if(n<2||n>49)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			for(int j=0;j<10;j++)
			{
				if(a[j]==n)
				{
					n-=a[j];
					cout<<j<<endl;
					break;
				}
				else
				{
					stick(n)
				}
			}
		}   
	}
		                                
	return 0;
}