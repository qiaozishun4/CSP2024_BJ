#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
int w[10]={6,2,5,5,4,5,6,3,7,6};
int a0[100010];
int ans[100010],lans;
bool cmp(int x[],int y[],int l1,int l2)
{
	int i=l1,j=l2;
	
	if (x[i]==0)
	{
		return 0;
	}
	if (i!=j)
	{
		return i<j;
	}
	for (;i>=1;i--)
	{
		if (x[i]!=y[i])
		{
			return x[i]<y[i];
		}
	}
	return 0;
}
void dfs(int n,int a[],int len)
{
	
	if (n==0)
	{
		if (cmp(a,ans,len,lans))
		{
			for (int i=1;i<=len;i++)
			{
				ans[i]=a[i];
				
			}
			lans=len;
		}
		
	}
	if (n<2)
	{
		return;
	}
	for (int i=0;i<10;i++)
	{
		if (n-w[i]>=0)
		{
//			cout<<n-w[i]<<"//"<<endl;
			len++;
			a[len]=i;
			dfs(n-w[i],a,len);
			a[len]=-1;
			len--;
		
		}
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	memset (a0,-1,sizeof(a0));
	
	while (T--)
	{
		cin>>n;
		memset(ans,0x3f,sizeof(ans));
		lans=100000;
		dfs(n,a0,0);
		if (ans[lans]!=0x3f3f3f3f)
		{
			for (int i=lans;i>=1;i--)
			{
				cout<<ans[i];
			}
			cout<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
	
	return 0;
}
