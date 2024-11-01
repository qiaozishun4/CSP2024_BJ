#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int box[1000005];
int maxx=0;
int f()
{
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		int j=i-1;
		while (box[j]!=box[i]&&j>=1) j--;
		if (j) sum+=bool(a[i]==a[j])*a[i];
	}
	return sum;
}
void dfs(int cur)
{
	if (cur>n)
	{
		maxx=max(maxx,f());
		return ;
	}
	for (int i=0;i<=1;i++)
	{
		box[cur]=i;
		dfs(cur+1);
	}
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		maxx=0;
		dfs(1);
		cout<<maxx<<endl;
	}
	return 0;
}
