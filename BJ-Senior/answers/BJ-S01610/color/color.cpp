#include<iostream>
using namespace std;
int a[100000];
int b[100000];
int n;
int ans1=0;
void dfs(int x,int r,int y)
{
	int r1=r,y1=y;
	if(x==n+1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[b[i]])
			ans+=a[i];
		}
		if(ans>ans1)
		ans1=ans;
		return;
	}
	for(int i=1;i<=2;i++)
	{
		if(i==1)
		{
			b[x]=r;
			r1=x;
			dfs(x+1,r1,y);
		}
		else
		{
			b[x]=y;
			y1=x;
			dfs(x+1,r,y1);
		}
	}
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		dfs(1,0,0);
		cout<<ans1<<endl;
		ans1=0;
	}
	return 0;
}
